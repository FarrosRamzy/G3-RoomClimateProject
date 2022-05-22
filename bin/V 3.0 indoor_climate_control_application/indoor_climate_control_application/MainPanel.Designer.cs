
namespace indoor_climate_control_application
{
    partial class MainPanel
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainPanel));
            this.ButtonPanel = new System.Windows.Forms.Panel();
            this.DatabaseFormButton = new System.Windows.Forms.Button();
            this.WeatherFormButton = new System.Windows.Forms.Button();
            this.RoomsFormButton = new System.Windows.Forms.Button();
            this.HomeFormButton = new System.Windows.Forms.Button();
            this.LogoPanel = new System.Windows.Forms.Panel();
            this.GroupLabel = new System.Windows.Forms.Label();
            this.LogoBox = new System.Windows.Forms.PictureBox();
            this.ViewFormPanel = new System.Windows.Forms.Panel();
            this.button1 = new System.Windows.Forms.Button();
            this.ExitButton = new System.Windows.Forms.Button();
            this.WindowButton = new System.Windows.Forms.Button();
            this.MinimizeButton = new System.Windows.Forms.Button();
            this.TitleLabel = new System.Windows.Forms.Label();
            this.TitlePanel = new System.Windows.Forms.Panel();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.ButtonPanel.SuspendLayout();
            this.LogoPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.LogoBox)).BeginInit();
            this.ViewFormPanel.SuspendLayout();
            this.TitlePanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // ButtonPanel
            // 
            this.ButtonPanel.BackColor = System.Drawing.Color.GhostWhite;
            this.ButtonPanel.Controls.Add(this.DatabaseFormButton);
            this.ButtonPanel.Controls.Add(this.WeatherFormButton);
            this.ButtonPanel.Controls.Add(this.RoomsFormButton);
            this.ButtonPanel.Controls.Add(this.HomeFormButton);
            this.ButtonPanel.Controls.Add(this.LogoPanel);
            this.ButtonPanel.Dock = System.Windows.Forms.DockStyle.Left;
            this.ButtonPanel.Location = new System.Drawing.Point(0, 0);
            this.ButtonPanel.Margin = new System.Windows.Forms.Padding(2);
            this.ButtonPanel.Name = "ButtonPanel";
            this.ButtonPanel.Size = new System.Drawing.Size(156, 492);
            this.ButtonPanel.TabIndex = 0;
            // 
            // DatabaseFormButton
            // 
            this.DatabaseFormButton.BackColor = System.Drawing.Color.GhostWhite;
            this.DatabaseFormButton.Dock = System.Windows.Forms.DockStyle.Top;
            this.DatabaseFormButton.FlatAppearance.BorderSize = 0;
            this.DatabaseFormButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.DatabaseFormButton.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DatabaseFormButton.Location = new System.Drawing.Point(0, 324);
            this.DatabaseFormButton.Margin = new System.Windows.Forms.Padding(2);
            this.DatabaseFormButton.Name = "DatabaseFormButton";
            this.DatabaseFormButton.Size = new System.Drawing.Size(156, 53);
            this.DatabaseFormButton.TabIndex = 3;
            this.DatabaseFormButton.Text = "Database";
            this.DatabaseFormButton.UseVisualStyleBackColor = false;
            this.DatabaseFormButton.Click += new System.EventHandler(this.DatabaseFormButton_Click);
            this.DatabaseFormButton.MouseHover += new System.EventHandler(this.DatabaseFormButton_MouseHover);
            // 
            // WeatherFormButton
            // 
            this.WeatherFormButton.BackColor = System.Drawing.Color.GhostWhite;
            this.WeatherFormButton.Dock = System.Windows.Forms.DockStyle.Top;
            this.WeatherFormButton.FlatAppearance.BorderSize = 0;
            this.WeatherFormButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.WeatherFormButton.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.WeatherFormButton.Location = new System.Drawing.Point(0, 271);
            this.WeatherFormButton.Margin = new System.Windows.Forms.Padding(2);
            this.WeatherFormButton.Name = "WeatherFormButton";
            this.WeatherFormButton.Size = new System.Drawing.Size(156, 53);
            this.WeatherFormButton.TabIndex = 2;
            this.WeatherFormButton.Text = "Weather";
            this.WeatherFormButton.UseVisualStyleBackColor = false;
            this.WeatherFormButton.Click += new System.EventHandler(this.WeatherFormButton_Click);
            this.WeatherFormButton.MouseHover += new System.EventHandler(this.WeatherFormButton_MouseHover);
            // 
            // RoomsFormButton
            // 
            this.RoomsFormButton.BackColor = System.Drawing.Color.GhostWhite;
            this.RoomsFormButton.Dock = System.Windows.Forms.DockStyle.Top;
            this.RoomsFormButton.FlatAppearance.BorderSize = 0;
            this.RoomsFormButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.RoomsFormButton.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RoomsFormButton.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.RoomsFormButton.Location = new System.Drawing.Point(0, 218);
            this.RoomsFormButton.Margin = new System.Windows.Forms.Padding(2);
            this.RoomsFormButton.Name = "RoomsFormButton";
            this.RoomsFormButton.Size = new System.Drawing.Size(156, 53);
            this.RoomsFormButton.TabIndex = 1;
            this.RoomsFormButton.Text = "Rooms";
            this.RoomsFormButton.TextImageRelation = System.Windows.Forms.TextImageRelation.TextBeforeImage;
            this.RoomsFormButton.UseVisualStyleBackColor = false;
            this.RoomsFormButton.Click += new System.EventHandler(this.RoomsFormButton_Click);
            this.RoomsFormButton.MouseHover += new System.EventHandler(this.RoomsFormButton_MouseHover);
            // 
            // HomeFormButton
            // 
            this.HomeFormButton.BackColor = System.Drawing.Color.GhostWhite;
            this.HomeFormButton.Dock = System.Windows.Forms.DockStyle.Top;
            this.HomeFormButton.FlatAppearance.BorderSize = 0;
            this.HomeFormButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.HomeFormButton.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.HomeFormButton.Image = global::indoor_climate_control_application.Properties.Resources.home_icon_2;
            this.HomeFormButton.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.HomeFormButton.Location = new System.Drawing.Point(0, 165);
            this.HomeFormButton.Margin = new System.Windows.Forms.Padding(2);
            this.HomeFormButton.Name = "HomeFormButton";
            this.HomeFormButton.Size = new System.Drawing.Size(156, 53);
            this.HomeFormButton.TabIndex = 0;
            this.HomeFormButton.Text = "Home";
            this.HomeFormButton.TextImageRelation = System.Windows.Forms.TextImageRelation.TextBeforeImage;
            this.HomeFormButton.UseVisualStyleBackColor = false;
            this.HomeFormButton.Click += new System.EventHandler(this.HomeFormButton_Click);
            this.HomeFormButton.MouseHover += new System.EventHandler(this.HomeFormButton_MouseHover);
            // 
            // LogoPanel
            // 
            this.LogoPanel.Controls.Add(this.GroupLabel);
            this.LogoPanel.Controls.Add(this.LogoBox);
            this.LogoPanel.Dock = System.Windows.Forms.DockStyle.Top;
            this.LogoPanel.Location = new System.Drawing.Point(0, 0);
            this.LogoPanel.Margin = new System.Windows.Forms.Padding(2);
            this.LogoPanel.Name = "LogoPanel";
            this.LogoPanel.Size = new System.Drawing.Size(156, 165);
            this.LogoPanel.TabIndex = 0;
            this.LogoPanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.LogoPanel_MouseDown);
            // 
            // GroupLabel
            // 
            this.GroupLabel.AutoSize = true;
            this.GroupLabel.Font = new System.Drawing.Font("Casanova Scotia", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.GroupLabel.Location = new System.Drawing.Point(6, 105);
            this.GroupLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.GroupLabel.Name = "GroupLabel";
            this.GroupLabel.Size = new System.Drawing.Size(151, 25);
            this.GroupLabel.TabIndex = 4;
            this.GroupLabel.Text = "Group #3";
            // 
            // LogoBox
            // 
            this.LogoBox.Image = global::indoor_climate_control_application.Properties.Resources.AiriosLogoIcon;
            this.LogoBox.Location = new System.Drawing.Point(32, 10);
            this.LogoBox.Margin = new System.Windows.Forms.Padding(2);
            this.LogoBox.Name = "LogoBox";
            this.LogoBox.Size = new System.Drawing.Size(84, 80);
            this.LogoBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.LogoBox.TabIndex = 0;
            this.LogoBox.TabStop = false;
            this.LogoBox.MouseDown += new System.Windows.Forms.MouseEventHandler(this.LogoBox_MouseDown);
            // 
            // ViewFormPanel
            // 
            this.ViewFormPanel.Controls.Add(this.button1);
            this.ViewFormPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ViewFormPanel.Location = new System.Drawing.Point(156, 0);
            this.ViewFormPanel.Margin = new System.Windows.Forms.Padding(2);
            this.ViewFormPanel.Name = "ViewFormPanel";
            this.ViewFormPanel.Size = new System.Drawing.Size(696, 492);
            this.ViewFormPanel.TabIndex = 2;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(0, 0);
            this.button1.Margin = new System.Windows.Forms.Padding(2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(56, 19);
            this.button1.TabIndex = 0;
            // 
            // ExitButton
            // 
            this.ExitButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.ExitButton.FlatAppearance.BorderSize = 0;
            this.ExitButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.ExitButton.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ExitButton.Location = new System.Drawing.Point(664, 2);
            this.ExitButton.Margin = new System.Windows.Forms.Padding(2);
            this.ExitButton.Name = "ExitButton";
            this.ExitButton.Size = new System.Drawing.Size(30, 32);
            this.ExitButton.TabIndex = 0;
            this.ExitButton.Text = "X";
            this.ExitButton.UseVisualStyleBackColor = true;
            this.ExitButton.Click += new System.EventHandler(this.ExitButton_Click);
            // 
            // WindowButton
            // 
            this.WindowButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.WindowButton.FlatAppearance.BorderSize = 0;
            this.WindowButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.WindowButton.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.WindowButton.Location = new System.Drawing.Point(629, 2);
            this.WindowButton.Margin = new System.Windows.Forms.Padding(2);
            this.WindowButton.Name = "WindowButton";
            this.WindowButton.Size = new System.Drawing.Size(30, 32);
            this.WindowButton.TabIndex = 1;
            this.WindowButton.Text = "O";
            this.WindowButton.UseVisualStyleBackColor = true;
            this.WindowButton.Click += new System.EventHandler(this.WindowButton_Click);
            // 
            // MinimizeButton
            // 
            this.MinimizeButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.MinimizeButton.FlatAppearance.BorderSize = 0;
            this.MinimizeButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.MinimizeButton.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MinimizeButton.Location = new System.Drawing.Point(595, 2);
            this.MinimizeButton.Margin = new System.Windows.Forms.Padding(2);
            this.MinimizeButton.Name = "MinimizeButton";
            this.MinimizeButton.Size = new System.Drawing.Size(30, 32);
            this.MinimizeButton.TabIndex = 2;
            this.MinimizeButton.Text = "–";
            this.MinimizeButton.UseVisualStyleBackColor = true;
            this.MinimizeButton.Click += new System.EventHandler(this.MinimizeButton_Click);
            // 
            // TitleLabel
            // 
            this.TitleLabel.AutoSize = true;
            this.TitleLabel.Font = new System.Drawing.Font("Casanova Scotia", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TitleLabel.Location = new System.Drawing.Point(278, 27);
            this.TitleLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.TitleLabel.Name = "TitleLabel";
            this.TitleLabel.Size = new System.Drawing.Size(97, 29);
            this.TitleLabel.TabIndex = 3;
            this.TitleLabel.Text = "Home";
            this.TitleLabel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.TitleLabel_MouseDown);
            // 
            // TitlePanel
            // 
            this.TitlePanel.BackColor = System.Drawing.Color.GhostWhite;
            this.TitlePanel.Controls.Add(this.TitleLabel);
            this.TitlePanel.Controls.Add(this.MinimizeButton);
            this.TitlePanel.Controls.Add(this.ExitButton);
            this.TitlePanel.Controls.Add(this.WindowButton);
            this.TitlePanel.Dock = System.Windows.Forms.DockStyle.Top;
            this.TitlePanel.Location = new System.Drawing.Point(156, 0);
            this.TitlePanel.Margin = new System.Windows.Forms.Padding(2);
            this.TitlePanel.Name = "TitlePanel";
            this.TitlePanel.Size = new System.Drawing.Size(696, 81);
            this.TitlePanel.TabIndex = 3;
            this.TitlePanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.TitlePanel_MouseDown);
            // 
            // MainPanel
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(852, 492);
            this.Controls.Add(this.TitlePanel);
            this.Controls.Add(this.ViewFormPanel);
            this.Controls.Add(this.ButtonPanel);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(2);
            this.MinimumSize = new System.Drawing.Size(856, 499);
            this.Name = "MainPanel";
            this.Text = "MainPanel";
            this.Load += new System.EventHandler(this.MainPanel_Load);
            this.ButtonPanel.ResumeLayout(false);
            this.LogoPanel.ResumeLayout(false);
            this.LogoPanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.LogoBox)).EndInit();
            this.ViewFormPanel.ResumeLayout(false);
            this.TitlePanel.ResumeLayout(false);
            this.TitlePanel.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel ButtonPanel;
        private System.Windows.Forms.Button DatabaseFormButton;
        private System.Windows.Forms.Button WeatherFormButton;
        private System.Windows.Forms.Button RoomsFormButton;
        private System.Windows.Forms.Button HomeFormButton;
        private System.Windows.Forms.Panel LogoPanel;
        private System.Windows.Forms.Panel ViewFormPanel;
        private System.Windows.Forms.Button ExitButton;
        private System.Windows.Forms.Button WindowButton;
        private System.Windows.Forms.Button MinimizeButton;
        private System.Windows.Forms.Label TitleLabel;
        private System.Windows.Forms.Panel TitlePanel;
        private System.Windows.Forms.Label GroupLabel;
        private System.Windows.Forms.PictureBox LogoBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Timer timer1;
    }
}

