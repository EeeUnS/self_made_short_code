using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;


namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        Boolean isBusy;
        private string filePath = null;
        public Form1()
        {
            InitializeComponent();
        }

        private void Label1_Click(object sender, EventArgs e)
        {

        }

        private void BtnDown_Click(object sender, EventArgs e)
        {
            if(isBusy)
            {
                webClient.CancelAsync();
                isBusy = false;
            }
            else
            {
                try
                {
                    var strFileName = this.txtUrl.Text.Split(new char[] { '/' });
                    System.Array.Reverse(strFileName);
                    Uri uri = new Uri(this.txtUrl.Text);
                    var str = webClient.DownloadString(uri);
                    webClient.DownloadString(uri);
                    webClient.DownloadFileAsync(uri, filePath + @"\" + strFileName[0]);
                    isBusy = true;
                }

                catch
                {
                    this.btnDown.Enabled = false;
                    MessageBox.Show("다운로드를 실패하였습니다.", "에러", 
                        MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        private void BtnFolder_Click(object sender, EventArgs e)
        {
            if(this.fbdFile.ShowDialog() == DialogResult.OK)
            {
                this.btnDown.Enabled = true;
                filePath = this.fbdFile.SelectedPath;
            }
        }

        private void WebClient_DownloadProgressChanged(object sender, System.Net.DownloadProgressChangedEventArgs e)
        {
            this.pgbDownload.Value = e.ProgressPercentage;
        }

        private void WebClient_DownloadFileCompleted(object sender, AsyncCompletedEventArgs e)
        {
            isBusy = false;
            this.btnDown.Enabled = false;
            if(e.Error == null)
            {
                if(this.cbOpen.Checked == false)
                {
                    MessageBox.Show("다운로드가 완료되었습니다.", "알림", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    Process myProcess = new Process();
                    myProcess.StartInfo.FileName = filePath;
                    myProcess.Start();
                }
            }
            else
            {
                MessageBox.Show("다운로드가 실패 하였습니다:" + e.Error.Message.ToString());
            }
        }
    }
}
