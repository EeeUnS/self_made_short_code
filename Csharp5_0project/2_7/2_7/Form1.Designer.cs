namespace _2_7
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
            this.lvcall = new System.Windows.Forms.ListView();
            this.btnSave = new System.Windows.Forms.Button();
            this.lbname = new System.Windows.Forms.Label();
            this.lbphone = new System.Windows.Forms.Label();
            this.txtname = new System.Windows.Forms.TextBox();
            this.txtphone = new System.Windows.Forms.TextBox();
            this.chname = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chphone = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SuspendLayout();
            // 
            // lvcall
            // 
            this.lvcall.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chname,
            this.chphone});
            this.lvcall.FullRowSelect = true;
            this.lvcall.GridLines = true;
            this.lvcall.Location = new System.Drawing.Point(30, 31);
            this.lvcall.Name = "lvcall";
            this.lvcall.Size = new System.Drawing.Size(259, 178);
            this.lvcall.TabIndex = 0;
            this.lvcall.UseCompatibleStateImageBehavior = false;
            this.lvcall.View = System.Windows.Forms.View.Details;
            this.lvcall.SelectedIndexChanged += new System.EventHandler(this.Lvcall_SelectedIndexChanged);
            this.lvcall.Click += new System.EventHandler(this.Lvcall_Click);
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(271, 250);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(82, 62);
            this.btnSave.TabIndex = 1;
            this.btnSave.Text = "입력";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.BtnSave_Click);
            // 
            // lbname
            // 
            this.lbname.AutoSize = true;
            this.lbname.Location = new System.Drawing.Point(22, 259);
            this.lbname.Name = "lbname";
            this.lbname.Size = new System.Drawing.Size(29, 12);
            this.lbname.TabIndex = 2;
            this.lbname.Text = "이름";
            // 
            // lbphone
            // 
            this.lbphone.AutoSize = true;
            this.lbphone.Location = new System.Drawing.Point(22, 310);
            this.lbphone.Name = "lbphone";
            this.lbphone.Size = new System.Drawing.Size(53, 12);
            this.lbphone.TabIndex = 3;
            this.lbphone.Text = "전화번호";
            // 
            // txtname
            // 
            this.txtname.Location = new System.Drawing.Point(96, 258);
            this.txtname.Name = "txtname";
            this.txtname.Size = new System.Drawing.Size(156, 21);
            this.txtname.TabIndex = 4;
            // 
            // txtphone
            // 
            this.txtphone.Location = new System.Drawing.Point(96, 307);
            this.txtphone.Name = "txtphone";
            this.txtphone.Size = new System.Drawing.Size(156, 21);
            this.txtphone.TabIndex = 5;
            // 
            // chname
            // 
            this.chname.Text = "이름";
            this.chname.Width = 95;
            // 
            // chphone
            // 
            this.chphone.Text = "전화번호";
            this.chphone.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.chphone.Width = 133;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(449, 360);
            this.Controls.Add(this.txtphone);
            this.Controls.Add(this.txtname);
            this.Controls.Add(this.lbphone);
            this.Controls.Add(this.lbname);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.lvcall);
            this.Name = "Form1";
            this.Text = "헤더 정렬";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView lvcall;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Label lbname;
        private System.Windows.Forms.Label lbphone;
        private System.Windows.Forms.TextBox txtname;
        private System.Windows.Forms.TextBox txtphone;
        private System.Windows.Forms.ColumnHeader chname;
        private System.Windows.Forms.ColumnHeader chphone;
    }
}

