using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.VisualBasic;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {

        string[] i = new string[366];
        string stryear = DateTime.Now.Year.ToString();

        public Form1()
        {
            InitializeComponent();
        }

        private void Btnsave_Click(object sender, EventArgs e)
        {
            var datTim1 = Convert.ToDateTime("#1/1/" + stryear + "#");
            DateTime datTim2 = this.dtptime.Value;

            int wD = Convert.ToInt32(DateAndTime.DateDiff(DateInterval.Day, datTim1, datTim2, FirstDayOfWeek.Sunday, FirstWeekOfYear.Jan1));
            i[wD] = this.txtmemo.Text;
            if(i[wD].Length > 0)
            {
                MessageBox.Show("일기가 정상적으로 저장되었습니다.", "알림", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.txtmemo.Clear();


            }


        }

        private void Dtptime_ValueChanged(object sender, EventArgs e)
        {
            DateTime datTim1 = Convert.ToDateTime("#1/1/" + stryear + "#");
            DateTime datTim2 = this.dtptime.Value;
            int wD = Convert.ToInt32(DateAndTime.DateDiff(DateInterval.Day, datTim1, datTim2, FirstDayOfWeek.Sunday, FirstWeekOfYear.Jan1));
            this.txtmemo.Text = i[wD];
        }
    }
}
