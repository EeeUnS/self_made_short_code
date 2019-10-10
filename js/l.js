// ==UserScript==
// @name        HV Random Encounter Notification
// @namespace   sigo8@e-hentai.org
// @author      sigo8, LangTuTaiHoa, GaryMcNabb, Owyn, sddsd, Superlatanium
// @version     2.0.2
// @match       https://hentaiverse.org/
// @match       https://hentaiverse.org/?*
// @exclude     https://hentaiverse.org/pages/showequip*
// @run-at      document-end
// @grant       GM_getResourceURL
// resource    alertToneQuite http://www.freesound.org/data/previews/234/234524_4019029-lq.mp3
// @resource    alertTone http://www.freesound.org/data/previews/234/234564_4019029-lq.mp3
// ==/UserScript==
// Sound source http://www.freesound.org/people/FoolBoyMedia/sounds/234524/
// http://www.freesound.org/people/FoolBoyMedia/sounds/234524/
'use strict';

var settings = {
  encounterURL: "https://e-hentai.org/news.php",//https://e-hentai.org/news.php?ponymode=on
  showDuringBattle: true,
  showDuringRiddle: true,
  openInNewTab: true,
  useNotifications: true,
  volumeMax: 1.0,
  volumeMid: 0.5,
};

var ONE_DAY = 86400000;
var ONE_HOUR = 3600000;
var HALF_HOUR = 1800000;
var SIX_MIN = 360000;

var battleLog = document.getElementById("togpane_log");
var riddleForm = document.getElementById("riddleform");
var timerDiv, timerLink, countText, incCountButton, decCountButton;
var logRows, nextEventTime, nextDawnTime, lastEventTime, eventCount;
var alertTone, audioDiv, fastTimerID, slowTimerID;
var Notifi = (settings.useNotifications && window.Notification) ||
    { permission: 'denied' };

if(!localStorage.lastRandomEncounter) {
  localStorage.lastRandomEncounter = lastEventTime = Date.now();
} else {
  lastEventTime = Number(localStorage.lastRandomEncounter);
}
if(!Number(localStorage.dailyRandomEncounterCount)) {
  localStorage.dailyRandomEncounterCount = 0;
}

if(battleLog && lastEventTime + HALF_HOUR <= Date.now()) {
  logRows = battleLog.firstElementChild.firstElementChild.children;
  if(logRows[0].firstElementChild.textContent === '0' &&
      /\brandom\b/i.test(logRows[logRows.length-2].textContent)) {
    localStorage.lastRandomEncounter = lastEventTime = Date.now();
    localStorage.dailyRandomEncounterCount++;
    localStorage.removeItem('randomEncounterNotificationDone');
  }
}
if(
  (settings.showDuringBattle || !battleLog) &&
  (settings.showDuringRiddle || !riddleForm)
  ) {
  timerDiv = makeHTML();
  timerLink = timerDiv.querySelector('#random_encounter_timer');
  countText = timerDiv.querySelector('#random_encounter_count');
  incCountButton = timerDiv.querySelector('#random_encounter_count_inc');
  decCountButton = timerDiv.querySelector('#random_encounter_count_dec');
  audioDiv  = timerDiv.querySelector('#audio_div');
  alertTone = makeAudio();
  timerDiv.appendChild(alertTone);

  eventCount = Number(localStorage.dailyRandomEncounterCount);
  countText.textContent = eventCount;
  restoreVolume();

  timerLink.addEventListener('click', timerReset, false);
  incCountButton.addEventListener('click', incCountCB, false);
  decCountButton.addEventListener('click', decCountCB, false);
  audioDiv.addEventListener('click', toggleAudio, false);
  window.addEventListener('storage', storageEventCB, false);

  if(settings.openInNewTab) {
    timerLink.target='_blank';
  }

  updateEventTimes();
  document.body.appendChild(timerDiv);
}
if(!battleLog && !riddleForm && Notifi.permission === 'default') {
  Notifi.requestPermission();
}

function updateEventTimes() {
  nextDawnTime = Math.ceil(lastEventTime / ONE_DAY) * ONE_DAY;
  if(eventCount >= 24) {
    nextEventTime = nextDawnTime;
  } else {
    nextEventTime = Math.min(nextDawnTime, lastEventTime + HALF_HOUR);
  }
  timerUpdate();
}

function timerUpdate() {
  var hour, minute, second;
  var time = nextEventTime - Date.now();
  if(time < 0) {
    timerLink.classList.add('ready');
    timerLink.textContent = "Ready";
    timerLink.href = settings.encounterURL;
    if(fastTimerID) {
      doNotification();
      clearInterval(fastTimerID);
      fastTimerID = 0;
    }
    if(slowTimerID) {
      clearInterval(slowTimerID);
      slowTimerID = 0;
    }
    return;
  }
  if(timerLink.classList.contains('disabled')) {
    timerLink.removeAttribute('href');
    timerLink.classList.remove('disabled');
  }
  timerLink.classList.remove('ready');
  if(time > ONE_HOUR) {
    hour = Math.round(time * 10 / ONE_HOUR) / 10;
    timerLink.textContent = hour + "h";
    if(fastTimerID) {
      clearInterval(fastTimerID);
      fastTimerID = 0;
    }
    if(!slowTimerID) {
      slowTimerID = setInterval(timerUpdate, SIX_MIN);
    }
    return;
  }
  time = Math.round(time / 1000);
  minute = Math.floor(time / 60);
  second = time % 60;
  timerLink.textContent = minute + ":" + (second < 10 ? "0" : "") + second;
  if(slowTimerID) {
    clearInterval(slowTimerID);
    slowTimerID = 0;
  }
  if(!fastTimerID) {
    fastTimerID = setInterval(timerUpdate, 1000);
  }
}

function timerReset(e) {
  //console.log(e);
  if(e  && e.altKey) {
    e.preventDefault();
    return;
  }
  var now = Date.now()
  if(now >= nextDawnTime) {
    eventCount = 0;
  } else if(now >= nextEventTime) {
  //{//lastEventTime + HALF_HOUR <= Date.now() nextEventTime
    eventCount = Math.min(Math.max(0, eventCount + 1), 24);
  }
  lastEventTime = now;
  updateEventTimes();
  timerLink.classList.add('disabled');
  countText.textContent = eventCount;
  localStorage.lastRandomEncounter = lastEventTime;
  localStorage.dailyRandomEncounterCount = eventCount;
  localStorage.removeItem('randomEncounterNotificationDone');
}

function doNotification() {
  // Minimize redundant notifications.
  // No race protections, but race conditions should be rare enough
  // to be acceptable.
  if(localStorage.randomEncounterNotificationDone &&
    Number(localStorage.dailyRandomEncounterCount) === eventCount) {
    return;
  }
  localStorage.randomEncounterNotificationDone = '1';
  if(Notifi.permission === 'granted') {
    new Notifi('Random Encounter');
  }
  alertTone.load();
  alertTone.play();
}

function storageEventCB(e) {
  switch(e.key) {
  case 'dailyRandomEncounterCount':
    eventCount = Number(localStorage.dailyRandomEncounterCount);
    countText.textContent = eventCount;
    break;
  case 'lastRandomEncounter':
    lastEventTime = Number(localStorage.lastRandomEncounter);
    break;
  case 'randomEncounterAlertVolume':
    restoreVolume();
    return;
  case 'randomEncounterNotificationDone':
    break;
  default:
    return;
  }
  updateEventTimes();
}

function incCountCB(e) {
  if(e && e.ctrlKey) {
    eventCount = 24;
  } else {
    eventCount = Math.min(Math.max(0, eventCount + 1), 24);
  }
  countText.textContent = eventCount;
  localStorage.dailyRandomEncounterCount = eventCount;
  updateEventTimes();
}

function decCountCB(e) {
  if(e && e.ctrlKey) {
    eventCount = 0;
  } else {
    eventCount = Math.min(Math.max(0, eventCount - 1), 24);
  }
  countText.textContent = eventCount;
  localStorage.dailyRandomEncounterCount = eventCount;
  updateEventTimes();
}

function toggleAudio() {
  var vol;
  switch(audioDiv.className) {
  case '':
    if(settings.volumeMid !== settings.volumeMax) {
      audioDiv.className = 'volume-half';
      alertTone.muted = false;
      vol = settings.volumeMid;
      break;
    } // else fallthrough
  case 'volume-half':
    audioDiv.className = 'muted';
    alertTone.muted = true;
    vol = 0;
    break;
  case 'muted': default:
    audioDiv.className = '';
    alertTone.muted = false;
    vol = settings.volumeMax;
    break;
  }
  localStorage.randomEncounterAlertVolume = alertTone.volume = vol;
  alertTone.load();
  alertTone.play();
}

function restoreVolume() {
  var vol = Number(localStorage.randomEncounterAlertVolume);
  if(isFinite(vol)) {
    if(vol === 0) {
      audioDiv.className = 'muted';
      alertTone.muted = true;
    } else if(vol <= settings.volumeMid &&
        settings.volumeMid !== settings.volumeMax) {
      audioDiv.className = 'volume-half';
      alertTone.muted = false;
    } else {
      audioDiv.className = '';
      alertTone.muted = false;
    }
    alertTone.volume = vol;
  } else {
    audioDiv.className = '';
    alertTone.muted = false;
    alertTone.volume = settings.volumeMax;
  }
}

function makeHTML() {
  var HTML = [
    '<div id="random_encounter_main_box">',
    '<style>',
    '#random_encounter_main_box {',
    '  position: absolute;',
    '  top: 3px;',
    '  left: 644px;',
    '  width: 90px;',
    '  text-align: center;',
    '  z-index: 11;',
    '}',
    '#random_encounter_count_dec, #random_encounter_count_inc {',
    '  float: left;',
    '  margin-top: 3px;',
    '  border: 1px solid;',
    '  border-radius: 8px;',
    '  width: 7px;',
    '  height: 7px;',
    '  cursor: pointer;',
    '}',
    '#random_encounter_count_dec :first-child {',
    '  border-top: 1px solid currentcolor !important;',
    '  margin-top: 3px;',
    '  margin-left: 2px;',
    '  width: 3px;',
    '}',
    '#random_encounter_count_inc>:first-child {',
    '  border-top: 1px solid currentcolor !important;',
    '  margin-top: 3px;',
    '  margin-left: 1px;',
    '  width: 5px;',
    '}',
    '#random_encounter_count_inc>:last-child {',
    '  border-left: 1px solid currentcolor !important;',
    '  margin-top: -3px;',
    '  margin-left: 3px;',
    '  height: 5px;',
    '}',
    '#random_encounter_count {',
    '  float: left;',
    '  margin-top: 3px;',
    '  font-size: 9px;',
    '  line-height: 9px;',
    '  width: 12px;',
    '}',
    '#random_encounter_timer {',
    '  cursor: pointer;',
    '  font-size: 20px;',
    '  font-weight: bold;',
    '  text-decoration: none;',
    '  float: right;',
    '  text-align: right;',
    '  width: 60px;',
    '}',
    '#random_encounter_timer.ready {',
    '  color: red !important;',
    '}',
    '#random_encounter_timer.disabled {',
    //'  visibility: hidden;',
    '  pointer-events: none;',
    '}',
    '#audio_div {',
    '  cursor: pointer;',
    '  float: left;',
    '  width: 10px;',
    '}',
    '#audio_div>:first-child {',
    '  float: left;',
    '  border-top: 5px solid transparent !important;',
    '  border-bottom: 5px solid transparent !important;',
    '  border-right: 5px solid currentcolor !important;',
    '}',
    '#audio_div>:nth-last-child(2) {',
    '  float: left;',
    '  border-radius: 100px;',
    '  border-right: 1px solid currentcolor !important;',
    '  height: 6px;',
    '  width: 6px;',
    '  margin-left: -4px;',
    '  margin-top: 2px;',
    '  margin-right: -3px;',
    '}',
    '#audio_div>:last-child {',
    '  float: left;',
    '  border-radius: 100px;',
    '  border-right: 1px solid currentcolor !important;',
    '  height: 10px;',
    '  width: 10px;',
    '  margin-left: -6px;',
    '}',
    '#audio_div.muted>:nth-last-child(2),',
    '#audio_div.muted>:last-child,',
    '#audio_div.volume-half>:last-child {',
    '  display: none;',
    '}',
    '</style>',
    '<div id="random_encounter_count_dec"><div></div></div>',
    '<div id="random_encounter_count">0</div>',
    '<div id="random_encounter_count_inc"><div></div><div></div></div>',
    '<a id="random_encounter_timer">0:00</a>',
    '<div id="audio_div"><div></div><div></div><div></div></div>',
    '</div>',
  ].join('\n');
  var div = document.createElement("div");
  div.innerHTML = HTML;
  return div.firstElementChild;
}



function makeAudio() {
  var a, src;
  if(settings.useFallBackBeep) {
    a = new Audio('data:audio/mpeg;base64,'+
'/+MYxAAKCJLQeUgAAAxthwHd3d3/hERE/d3d/lJFwVgDgAwA4Lz5QEOD//z/Kef6Pf//9/QqgAFA'+
'wwgEAABSIsQImf9ExSL3/+MYxBIReT7lmZQoAvkCMQGhgnagAVCHiZgZoqRMRFSoY3/4CgCAIkHg'+
'8Ih3//w6DQVBURHv+VBURBUFREe//DX//v27wMAk/+MYxAcMYMpQAZcoAAZoDLn0rgDBwgQKBgFw'+
'PGBi0ipyBgdYIHAwIMHwAxGhVsAwF0Dkgb4L8NX//995qMx6Nxr//+Z18ojD/+MYxBAQESbIAZo4'+
'AA/rcvgEzceK2H0NgubOvMvMW+YX+jHnuwBQAoQERGH/8y7+cNSgCad/6izQklv/4xXD58+jXgq1'+
'WxpX/+MYxAoO8Mp4Ac8YAa9e0Yk8hzLIrkOUU5+i2iaoUuUNUMXwU6dMc/TRUMWErmZ9qE+fbigu'+
'IKwFHQjsQXopTEFNRTMuOTku');
    return a;
  }
  if(typeof GM_getResourceURL === 'function') {
    src = GM_getResourceURL('alertTone');
    src = src.replace(/^data:application;/, 'data:audio/mpeg;');
    a = new Audio(src);
    return a;
  }
  a = new Audio('http://www.freesound.org/data/previews/234/234564_4019029-lq.mp3');
  return a;
}
