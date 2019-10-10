// ==UserScript==
// @name        네이버 파케 게시판 미리보기 + 댓글 작성 보호 + 댓글 강조 + 댓글 GIF 자동재생
// @namespace    https://www.cafe.naver.com/
// @version      0.1
// @description  클리앙 게시판에서 글 내용 미리보기 + 댓글 작성 도중엔 페이지 나가지 않도록 확인창 띄우기 + 댓글 강조 + 댓글 GIF 자동재생
// @author       Myayu
// @match        https://www.cafe.naver.com/*
// @grant        none
// ==/UserScript==
(
    function() 
    {
        var is_board =  document.URL.match(/cafe.naver.co\/?(\w*)/);
        if(
            !(is_board[1] == 'board' || is_board[1] =='group'))
            {
                return;
            }
        if(is_board[3])
        {
            $("div.comment-row.by-me").attr("style","background-color: #eeeeff;");
            $("div.comment-row.by-author").attr("style","background-color: #ffffee;");
            $("span.icon-gif").attr("style","display:none;");
            setInterval(function()
                {
                    $("div.comment-row.by-me").attr("style","background-color: #eeeeff;");
                    $("div.comment-row.by-author").attr("style","background-color: #ffffee;");
                    $("img.lazy").each(function() {
                        var get_src = $(this).attr("src");
                        if(!get_src.match(/.+(&gif=true)$/))
                        {
                            $(this).attr("src",get_src+"&gif=true");
                            $("span.icon-gif").attr("style","display:none;");
                        }
                    }
                    );
                    $("span.icon-gif").attr("style","display:none;");
                },
                500);
            $(window).bind('beforeunload', function() 
            {
                if($("div.fr-wrapper > div").text() !=='') 
                {
                    return '작성 중인 댓글이 있습니다. 페이지에서 나가시겠습니까?';
                }
            }
            );
        }
        else
        {
            $("div.list-title > a.list-subject").each(function() {$(this).attr("title",$(this).parent().find("div.card-content.has-image>div.card-preview").text());});}
        }
        )();