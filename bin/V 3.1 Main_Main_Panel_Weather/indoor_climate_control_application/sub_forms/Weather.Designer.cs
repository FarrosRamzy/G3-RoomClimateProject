
namespace indoor_climate_control_application.subForms
{
    partial class Weather
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Weather));
            this.lblWindStatus = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.lblCurrentTemp = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.lblLowestTemp = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.lblCloud = new System.Windows.Forms.Label();
            this.btnChangeCity = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.lblHumid = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.lblHighestTemp = new System.Windows.Forms.Label();
            this.tbCityName = new System.Windows.Forms.TextBox();
            this.pbHumid = new System.Windows.Forms.PictureBox();
            this.pbCloud = new System.Windows.Forms.PictureBox();
            this.weather_timer = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.pbHumid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbCloud)).BeginInit();
            this.SuspendLayout();
            // 
            // lblWindStatus
            // 
            this.lblWindStatus.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.lblWindStatus.BackColor = System.Drawing.Color.Transparent;
            this.lblWindStatus.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.lblWindStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblWindStatus.Location = new System.Drawing.Point(211, 166);
            this.lblWindStatus.Margin = new System.Windows.Forms.Padding(0);
            this.lblWindStatus.Name = "lblWindStatus";
            this.lblWindStatus.Size = new System.Drawing.Size(359, 52);
            this.lblWindStatus.TabIndex = 44;
            this.lblWindStatus.Text = "Today wind is 90 m/s to the west";
            this.lblWindStatus.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // label6
            // 
            this.label6.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label6.BackColor = System.Drawing.Color.Transparent;
            this.label6.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 33F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(157, 226);
            this.label6.Margin = new System.Windows.Forms.Padding(0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(62, 62);
            this.label6.TabIndex = 43;
            this.label6.Text = "℃";
            this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblCurrentTemp
            // 
            this.lblCurrentTemp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblCurrentTemp.BackColor = System.Drawing.Color.Transparent;
            this.lblCurrentTemp.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.lblCurrentTemp.Font = new System.Drawing.Font("Microsoft Sans Serif", 33F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCurrentTemp.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblCurrentTemp.Location = new System.Drawing.Point(71, 226);
            this.lblCurrentTemp.Margin = new System.Windows.Forms.Padding(0);
            this.lblCurrentTemp.Name = "lblCurrentTemp";
            this.lblCurrentTemp.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.lblCurrentTemp.Size = new System.Drawing.Size(86, 61);
            this.lblCurrentTemp.TabIndex = 42;
            this.lblCurrentTemp.Text = "-888";
            this.lblCurrentTemp.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // label5
            // 
            this.label5.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label5.BackColor = System.Drawing.Color.Transparent;
            this.label5.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(251, 316);
            this.label5.Margin = new System.Windows.Forms.Padding(0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(31, 30);
            this.label5.TabIndex = 40;
            this.label5.Text = "℃";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblLowestTemp
            // 
            this.lblLowestTemp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblLowestTemp.BackColor = System.Drawing.Color.Transparent;
            this.lblLowestTemp.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.lblLowestTemp.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblLowestTemp.Location = new System.Drawing.Point(185, 327);
            this.lblLowestTemp.Margin = new System.Windows.Forms.Padding(0);
            this.lblLowestTemp.Name = "lblLowestTemp";
            this.lblLowestTemp.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.lblLowestTemp.Size = new System.Drawing.Size(74, 40);
            this.lblLowestTemp.TabIndex = 41;
            this.lblLowestTemp.Text = "0.00";
            this.lblLowestTemp.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // label4
            // 
            this.label4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(57, 327);
            this.label4.Margin = new System.Windows.Forms.Padding(0);
            this.label4.Name = "label4";
            this.label4.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.label4.Size = new System.Drawing.Size(112, 40);
            this.label4.TabIndex = 39;
            this.label4.Text = "Lowest";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // label3
            // 
            this.label3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(57, 287);
            this.label3.Margin = new System.Windows.Forms.Padding(0);
            this.label3.Name = "label3";
            this.label3.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.label3.Size = new System.Drawing.Size(112, 40);
            this.label3.TabIndex = 38;
            this.label3.Text = "Highest";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblCloud
            // 
            this.lblCloud.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.lblCloud.BackColor = System.Drawing.Color.Transparent;
            this.lblCloud.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.lblCloud.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCloud.Location = new System.Drawing.Point(291, 125);
            this.lblCloud.Margin = new System.Windows.Forms.Padding(0);
            this.lblCloud.Name = "lblCloud";
            this.lblCloud.Size = new System.Drawing.Size(204, 30);
            this.lblCloud.TabIndex = 37;
            this.lblCloud.Text = "Clear";
            this.lblCloud.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // btnChangeCity
            // 
            this.btnChangeCity.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnChangeCity.Cursor = System.Windows.Forms.Cursors.Default;
            this.btnChangeCity.FlatAppearance.BorderSize = 2;
            this.btnChangeCity.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnChangeCity.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnChangeCity.Location = new System.Drawing.Point(500, 83);
            this.btnChangeCity.Margin = new System.Windows.Forms.Padding(2);
            this.btnChangeCity.Name = "btnChangeCity";
            this.btnChangeCity.Size = new System.Drawing.Size(70, 40);
            this.btnChangeCity.TabIndex = 36;
            this.btnChangeCity.Text = "Change";
            this.btnChangeCity.UseVisualStyleBackColor = true;
            this.btnChangeCity.Click += new System.EventHandler(this.btnChangeCity_Click_1);
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 33F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(647, 296);
            this.label2.Margin = new System.Windows.Forms.Padding(0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 61);
            this.label2.TabIndex = 34;
            this.label2.Text = "%";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblHumid
            // 
            this.lblHumid.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.lblHumid.BackColor = System.Drawing.Color.Transparent;
            this.lblHumid.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.lblHumid.Font = new System.Drawing.Font("Microsoft Sans Serif", 33F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblHumid.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblHumid.Location = new System.Drawing.Point(519, 296);
            this.lblHumid.Margin = new System.Windows.Forms.Padding(0);
            this.lblHumid.Name = "lblHumid";
            this.lblHumid.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.lblHumid.Size = new System.Drawing.Size(128, 61);
            this.lblHumid.TabIndex = 35;
            this.lblHumid.Text = "0.00";
            this.lblHumid.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(251, 276);
            this.label1.Margin = new System.Windows.Forms.Padding(0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(31, 30);
            this.label1.TabIndex = 32;
            this.label1.Text = "℃";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblHighestTemp
            // 
            this.lblHighestTemp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblHighestTemp.BackColor = System.Drawing.Color.Transparent;
            this.lblHighestTemp.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.lblHighestTemp.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblHighestTemp.Location = new System.Drawing.Point(185, 287);
            this.lblHighestTemp.Margin = new System.Windows.Forms.Padding(0);
            this.lblHighestTemp.Name = "lblHighestTemp";
            this.lblHighestTemp.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.lblHighestTemp.Size = new System.Drawing.Size(74, 40);
            this.lblHighestTemp.TabIndex = 33;
            this.lblHighestTemp.Text = "0.00";
            this.lblHighestTemp.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // tbCityName
            // 
            this.tbCityName.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.tbCityName.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.tbCityName.Font = new System.Drawing.Font("Microsoft Sans Serif", 22.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbCityName.Location = new System.Drawing.Point(294, 80);
            this.tbCityName.Margin = new System.Windows.Forms.Padding(2);
            this.tbCityName.Name = "tbCityName";
            this.tbCityName.ReadOnly = true;
            this.tbCityName.Size = new System.Drawing.Size(202, 34);
            this.tbCityName.TabIndex = 31;
            // 
            // pbHumid
            // 
            this.pbHumid.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.pbHumid.Image = ((System.Drawing.Image)(resources.GetObject("pbHumid.Image")));
            this.pbHumid.Location = new System.Drawing.Point(466, 300);
            this.pbHumid.Name = "pbHumid";
            this.pbHumid.Size = new System.Drawing.Size(50, 50);
            this.pbHumid.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbHumid.TabIndex = 45;
            this.pbHumid.TabStop = false;
            // 
            // pbCloud
            // 
            this.pbCloud.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.pbCloud.BackColor = System.Drawing.SystemColors.Control;
            this.pbCloud.Location = new System.Drawing.Point(214, 83);
            this.pbCloud.Margin = new System.Windows.Forms.Padding(2);
            this.pbCloud.Name = "pbCloud";
            this.pbCloud.Size = new System.Drawing.Size(75, 81);
            this.pbCloud.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbCloud.TabIndex = 30;
            this.pbCloud.TabStop = false;
            // 
            // weather_timer
            // 
            this.weather_timer.Interval = 1000;
            this.weather_timer.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Weather
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.pbHumid);
            this.Controls.Add(this.lblWindStatus);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.lblCurrentTemp);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.lblLowestTemp);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.lblCloud);
            this.Controls.Add(this.btnChangeCity);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.lblHumid);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.lblHighestTemp);
            this.Controls.Add(this.tbCityName);
            this.Controls.Add(this.pbCloud);
            this.Name = "Weather";
            this.Text = "Weather";
            ((System.ComponentModel.ISupportInitialize)(this.pbHumid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbCloud)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pbHumid;
        private System.Windows.Forms.Label lblWindStatus;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label lblCurrentTemp;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label lblLowestTemp;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label lblCloud;
        private System.Windows.Forms.Button btnChangeCity;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lblHumid;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblHighestTemp;
        private System.Windows.Forms.PictureBox pbCloud;
        private System.Windows.Forms.Timer weather_timer;
        private System.Windows.Forms.TextBox tbCityName;
        private System.Windows.Forms.TextBox tbCityName1;
    }
}