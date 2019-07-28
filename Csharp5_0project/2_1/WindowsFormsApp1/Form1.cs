using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Label1_Click(object sender, EventArgs e)
        {

        }

        private void Label2_Click(object sender, EventArgs e)
        {

        }

        private void BtnLogin_Click(object sender, EventArgs e)
        {
            if (CheckData() == true)
            {
                this.IbIResult.Text = "로그인 성공";
            }
        }

        private void Label3_Click(object sender, EventArgs e)
        {

        }

        private bool CheckData()
        {
            if (this.txtId.Text == "")
            {
                MessageBox.Show("로그인 아이디를 입력하세요", "알림", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                this.txtId.Focus();
                return false;
            }
            else if (this.txtPwd.Text == "")
            {
                MessageBox.Show("로그인 아이디를 입력하세요", "알림", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                this.txtPwd.Focus();
                return false;
            }
            else if (this.txtId.Text == "test" && this.txtPwd.Text == "1234")
            {
                return true;
            }

            else if (this.txtId.Text == "test" && this.txtPwd.Text != "1234")
            {
                this.IbIResult.Text = "일치하는 비밀번호가 없습니다.";
                this.txtPwd.Focus();
                return false;
            }
            else
            {
                this.IbIResult.Text = "일치하는 아이디가 없습니다.";
                this.txtId.Focus();
                return false;
            }

        }

        private void BtnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void TxtPwd_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter && CheckData() == true)
            {
                this.IbIResult.Text = "로그인 성공";
            }
        }
    }

}
