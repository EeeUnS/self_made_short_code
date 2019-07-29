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
            this.dtptime = new System.Windows.Forms.DateTimePicker();
            this.btnsave = new System.Windows.Forms.Button();
            this.txtmemo = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // dtptime
            // 
            this.dtptime.Location = new System.Drawing.Point(73, 55);
            this.dtptime.Name = "dtptime";
            this.dtptime.Size = new System.Drawing.Size(200, 25);
            this.dtptime.TabIndex = 0;
            this.dtptime.ValueChanged += new System.EventHandler(this.Dtptime_ValueChanged);
            // 
            // btnsave
            // 
            this.btnsave.Location = new System.Drawing.Point(311, 55);
            this.btnsave.Name = "btnsave";
            this.btnsave.Size = new System.Drawing.Size(110, 25);
            this.btnsave.TabIndex = 1;
            this.btnsave.Text = "입력";
            this.btnsave.UseVisualStyleBackColor = true;
            this.btnsave.Click += new System.EventHandler(this.Btnsave_Click);
            // 
            // txtmemo
            // 
            this.txtmemo.Location = new System.Drawing.Point(63, 103);
            this.txtmemo.Multiline = true;
            this.txtmemo.Name = "txtmemo";
            this.txtmemo.Size = new System.Drawing.Size(384, 309);
            this.txtmemo.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(525, 450);
            this.Controls.Add(this.txtmemo);
            this.Controls.Add(this.btnsave);
            this.Controls.Add(this.dtptime);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.Text = "일기장";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DateTimePicker dtptime;
        private System.Windows.Forms.Button btnsave;
        private System.Windows.Forms.TextBox txtmemo;
    }
}

