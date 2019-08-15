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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.tlsmenu = new System.Windows.Forms.ToolStrip();
            this.colordlg = new System.Windows.Forms.ColorDialog();
            this.fontdlg = new System.Windows.Forms.FontDialog();
            this.rtbtext = new System.Windows.Forms.RichTextBox();
            this.tsbtnFont = new System.Windows.Forms.ToolStripButton();
            this.tsbtnColor = new System.Windows.Forms.ToolStripButton();
            this.tlsmenu.SuspendLayout();
            this.SuspendLayout();
            // 
            // tlsmenu
            // 
            this.tlsmenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbtnFont,
            this.tsbtnColor});
            this.tlsmenu.Location = new System.Drawing.Point(0, 0);
            this.tlsmenu.Name = "tlsmenu";
            this.tlsmenu.Size = new System.Drawing.Size(469, 25);
            this.tlsmenu.TabIndex = 0;
            this.tlsmenu.Text = "toolStrip1";
            // 
            // rtbtext
            // 
            this.rtbtext.Dock = System.Windows.Forms.DockStyle.Fill;
            this.rtbtext.Location = new System.Drawing.Point(0, 25);
            this.rtbtext.Name = "rtbtext";
            this.rtbtext.Size = new System.Drawing.Size(469, 342);
            this.rtbtext.TabIndex = 1;
            this.rtbtext.Text = "";
            // 
            // tsbtnFont
            // 
            this.tsbtnFont.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbtnFont.Image = ((System.Drawing.Image)(resources.GetObject("tsbtnFont.Image")));
            this.tsbtnFont.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtnFont.Name = "tsbtnFont";
            this.tsbtnFont.Size = new System.Drawing.Size(23, 22);
            this.tsbtnFont.Click += new System.EventHandler(this.TsbtnFont_Click);
            // 
            // tsbtnColor
            // 
            this.tsbtnColor.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbtnColor.Image = ((System.Drawing.Image)(resources.GetObject("tsbtnColor.Image")));
            this.tsbtnColor.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtnColor.Name = "tsbtnColor";
            this.tsbtnColor.Size = new System.Drawing.Size(23, 22);
            this.tsbtnColor.Text = "toolStripButton1";
            this.tsbtnColor.Click += new System.EventHandler(this.TsbtnColor_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(469, 367);
            this.Controls.Add(this.rtbtext);
            this.Controls.Add(this.tlsmenu);
            this.Name = "Form1";
            this.Text = "폰트 바꾸기";
            this.tlsmenu.ResumeLayout(false);
            this.tlsmenu.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip tlsmenu;
        private System.Windows.Forms.ColorDialog colordlg;
        private System.Windows.Forms.FontDialog fontdlg;
        private System.Windows.Forms.RichTextBox rtbtext;
        private System.Windows.Forms.ToolStripButton tsbtnFont;
        private System.Windows.Forms.ToolStripButton tsbtnColor;
    }
}

