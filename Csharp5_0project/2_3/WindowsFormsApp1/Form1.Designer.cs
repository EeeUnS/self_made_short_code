namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.lblselect = new System.Windows.Forms.Label();
            this.cbbselect = new System.Windows.Forms.ComboBox();
            this.lbResult = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // lblselect
            // 
            this.lblselect.AutoSize = true;
            this.lblselect.Location = new System.Drawing.Point(25, 37);
            this.lblselect.Name = "lblselect";
            this.lblselect.Size = new System.Drawing.Size(29, 12);
            this.lblselect.TabIndex = 0;
            this.lblselect.Text = "선택";
            // 
            // cbbselect
            // 
            this.cbbselect.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbbselect.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.cbbselect.FormattingEnabled = true;
            this.cbbselect.Items.AddRange(new object[] {
            "2 단",
            "3 단",
            "4 단",
            "5 단",
            "6 단",
            "7 단",
            "8 단",
            "9 단"});
            this.cbbselect.Location = new System.Drawing.Point(71, 32);
            this.cbbselect.Name = "cbbselect";
            this.cbbselect.Size = new System.Drawing.Size(161, 20);
            this.cbbselect.TabIndex = 1;
            this.cbbselect.SelectedIndexChanged += new System.EventHandler(this.Cbbselect_SelectedIndexChanged);
            // 
            // lbResult
            // 
            this.lbResult.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lbResult.FormattingEnabled = true;
            this.lbResult.ItemHeight = 12;
            this.lbResult.Location = new System.Drawing.Point(33, 83);
            this.lbResult.Name = "lbResult";
            this.lbResult.Size = new System.Drawing.Size(198, 206);
            this.lbResult.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(281, 339);
            this.Controls.Add(this.lbResult);
            this.Controls.Add(this.cbbselect);
            this.Controls.Add(this.lblselect);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "구구단";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblselect;
        private System.Windows.Forms.ComboBox cbbselect;
        private System.Windows.Forms.ListBox lbResult;
    }
}

