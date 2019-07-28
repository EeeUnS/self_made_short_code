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
            this.iblld = new System.Windows.Forms.Label();
            this.lblPwd = new System.Windows.Forms.Label();
            this.IbIResult = new System.Windows.Forms.Label();
            this.btnLogin = new System.Windows.Forms.Button();
            this.BtnClose = new System.Windows.Forms.Button();
            this.txtId = new System.Windows.Forms.TextBox();
            this.txtPwd = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // iblld
            // 
            this.iblld.AutoSize = true;
            this.iblld.Location = new System.Drawing.Point(96, 93);
            this.iblld.Name = "iblld";
            this.iblld.Size = new System.Drawing.Size(49, 12);
            this.iblld.TabIndex = 0;
            this.iblld.Text = "아이디 :";
            this.iblld.Click += new System.EventHandler(this.Label1_Click);
            // 
            // lblPwd
            // 
            this.lblPwd.AutoSize = true;
            this.lblPwd.Location = new System.Drawing.Point(96, 141);
            this.lblPwd.Name = "lblPwd";
            this.lblPwd.Size = new System.Drawing.Size(61, 12);
            this.lblPwd.TabIndex = 1;
            this.lblPwd.Text = "비밀번호 :";
            this.lblPwd.Click += new System.EventHandler(this.Label2_Click);
            // 
            // IbIResult
            // 
            this.IbIResult.AutoSize = true;
            this.IbIResult.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.IbIResult.ForeColor = System.Drawing.Color.Red;
            this.IbIResult.Location = new System.Drawing.Point(96, 262);
            this.IbIResult.Name = "IbIResult";
            this.IbIResult.Size = new System.Drawing.Size(31, 12);
            this.IbIResult.TabIndex = 2;
            this.IbIResult.Text = "결과";
            this.IbIResult.Click += new System.EventHandler(this.Label3_Click);
            // 
            // btnLogin
            // 
            this.btnLogin.Location = new System.Drawing.Point(70, 202);
            this.btnLogin.Name = "btnLogin";
            this.btnLogin.Size = new System.Drawing.Size(75, 23);
            this.btnLogin.TabIndex = 3;
            this.btnLogin.Text = "로그인";
            this.btnLogin.UseVisualStyleBackColor = true;
            this.btnLogin.Click += new System.EventHandler(this.BtnLogin_Click);
            // 
            // BtnClose
            // 
            this.BtnClose.Location = new System.Drawing.Point(188, 202);
            this.BtnClose.Name = "BtnClose";
            this.BtnClose.Size = new System.Drawing.Size(75, 23);
            this.BtnClose.TabIndex = 4;
            this.BtnClose.Text = "닫기";
            this.BtnClose.UseVisualStyleBackColor = true;
            this.BtnClose.Click += new System.EventHandler(this.BtnClose_Click);
            // 
            // txtId
            // 
            this.txtId.Location = new System.Drawing.Point(172, 93);
            this.txtId.Name = "txtId";
            this.txtId.Size = new System.Drawing.Size(100, 21);
            this.txtId.TabIndex = 5;
            // 
            // txtPwd
            // 
            this.txtPwd.Location = new System.Drawing.Point(172, 138);
            this.txtPwd.Name = "txtPwd";
            this.txtPwd.Size = new System.Drawing.Size(100, 21);
            this.txtPwd.TabIndex = 6;
            this.txtPwd.KeyDown += new System.Windows.Forms.KeyEventHandler(this.TxtPwd_KeyDown);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(373, 331);
            this.Controls.Add(this.txtPwd);
            this.Controls.Add(this.txtId);
            this.Controls.Add(this.BtnClose);
            this.Controls.Add(this.btnLogin);
            this.Controls.Add(this.IbIResult);
            this.Controls.Add(this.lblPwd);
            this.Controls.Add(this.iblld);
            this.Name = "Form1";
            this.Text = "로그인";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label iblld;
        private System.Windows.Forms.Label lblPwd;
        private System.Windows.Forms.Label IbIResult;
        private System.Windows.Forms.Button btnLogin;
        private System.Windows.Forms.Button BtnClose;
        private System.Windows.Forms.TextBox txtId;
        private System.Windows.Forms.TextBox txtPwd;
    }
}

