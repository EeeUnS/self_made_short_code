using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;



namespace _2_7
{
    public partial class Form1 : Form
    {
        private bool Isort = true;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private Boolean ControlCheck()
        {
            if(this.txtname.Text == "")
            {
                MessageBox.Show("이름을 입력하세요!!", "오류",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
                this.txtname.Focus();
                return false;
            }
            else if(this.txtphone.Text == "")
            {
                MessageBox.Show("전화번호를 입력하세요!!", "오류",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
                this.txtphone.Focus();
                return false;
            }
            else
            {
                return true;
            }
        }


        private void BtnSave_Click(object sender, EventArgs e)
        {
            if(ControlCheck() == true)
            {
                var strArray = new String[]
                { this.txtname.Text, this.txtphone.Text };
                var lvt = new ListViewItem(strArray);
                this.lvcall.Items.Add(lvt);
                this.txtname.Clear();
                this.txtphone.Clear();
            }
            else
            {
                return;
            }
        }

        private void Lvcall_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Lvcall_Click(object sender, EventArgs e)
        {
            if(Isort == true)
            {
                //this.lvcall.ListViewItemSorter = new listviewitemcomparer
            }
        }
    }
    class ListViewItemComparer : IComparer
    {
        private int col;
        private bool z;
        public ListViewItemComparer(int column, bool v)
        {
            col = column;
            z = v;
        }
        public int Compare(object x,object y)
        {
            object a, b;
            if(z == true)
            {
                a = x;
                b = y;
            }
            else
            {
                a = y;
                b = x;
            }
            return String.Compare(((ListViewItem)a).SubItems[col].Text, 
                ((ListViewItem)b).SubItems[col].Text);
        }
    }
}
