namespace _2_9
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
            this.pblmg = new System.Windows.Forms.PictureBox();
            this.btnshow = new System.Windows.Forms.Button();
            this.btnmag = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pblmg)).BeginInit();
            this.SuspendLayout();
            // 
            // pblmg
            // 
            this.pblmg.Image = ((System.Drawing.Image)(resources.GetObject("pblmg.Image")));
            this.pblmg.Location = new System.Drawing.Point(12, 12);
            this.pblmg.Name = "pblmg";
            this.pblmg.Size = new System.Drawing.Size(270, 167);
            this.pblmg.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pblmg.TabIndex = 0;
            this.pblmg.TabStop = false;
            this.pblmg.Click += new System.EventHandler(this.PictureBox1_Click);
            // 
            // btnshow
            // 
            this.btnshow.Location = new System.Drawing.Point(16, 206);
            this.btnshow.Name = "btnshow";
            this.btnshow.Size = new System.Drawing.Size(110, 36);
            this.btnshow.TabIndex = 1;
            this.btnshow.Text = "슬라이드열기";
            this.btnshow.UseVisualStyleBackColor = true;
            this.btnshow.Click += new System.EventHandler(this.Btnshow_Click);
            // 
            // btnmag
            // 
            this.btnmag.Location = new System.Drawing.Point(142, 206);
            this.btnmag.Name = "btnmag";
            this.btnmag.Size = new System.Drawing.Size(110, 36);
            this.btnmag.TabIndex = 2;
            this.btnmag.Text = "폼 붙이기 열기";
            this.btnmag.UseVisualStyleBackColor = true;
            this.btnmag.LocationChanged += new System.EventHandler(this.Btnmag_LocationChanged);
            this.btnmag.Click += new System.EventHandler(this.Btnmag_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(294, 271);
            this.Controls.Add(this.btnmag);
            this.Controls.Add(this.btnshow);
            this.Controls.Add(this.pblmg);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "폼 슬라이딩 붙이기";
            this.LocationChanged += new System.EventHandler(this.Form1_LocationChanged);
            ((System.ComponentModel.ISupportInitialize)(this.pblmg)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pblmg;
        private System.Windows.Forms.Button btnshow;
        private System.Windows.Forms.Button btnmag;
    }
}

