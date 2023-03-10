
namespace Main_Panel_Controls
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
            this.pnMenu = new System.Windows.Forms.Panel();
            this.pbLogo = new System.Windows.Forms.PictureBox();
            this.btnGraph = new System.Windows.Forms.Button();
            this.btnWeather = new System.Windows.Forms.Button();
            this.btnRooms = new System.Windows.Forms.Button();
            this.btnHome = new System.Windows.Forms.Button();
            this.pnLogo = new System.Windows.Forms.Panel();
            this.lblGroup = new System.Windows.Forms.Label();
            this.pnTitle = new System.Windows.Forms.Panel();
            this.lbBackToHome = new System.Windows.Forms.Label();
            this.btnMaximize = new System.Windows.Forms.Button();
            this.btnMinimize = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnBackToHome = new System.Windows.Forms.Button();
            this.lblTitle = new System.Windows.Forms.Label();
            this.pnDesktop = new System.Windows.Forms.Panel();
            this.pnMenu.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbLogo)).BeginInit();
            this.pnLogo.SuspendLayout();
            this.pnTitle.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnMenu
            // 
            this.pnMenu.BackColor = System.Drawing.Color.White;
            this.pnMenu.Controls.Add(this.pbLogo);
            this.pnMenu.Controls.Add(this.btnGraph);
            this.pnMenu.Controls.Add(this.btnWeather);
            this.pnMenu.Controls.Add(this.btnRooms);
            this.pnMenu.Controls.Add(this.btnHome);
            this.pnMenu.Controls.Add(this.pnLogo);
            this.pnMenu.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnMenu.Location = new System.Drawing.Point(0, 0);
            this.pnMenu.Margin = new System.Windows.Forms.Padding(2);
            this.pnMenu.Name = "pnMenu";
            this.pnMenu.Size = new System.Drawing.Size(165, 474);
            this.pnMenu.TabIndex = 0;
            // 
            // pbLogo
            // 
            this.pbLogo.Image = global::Main_Panel_Controls.Properties.Resources.AiriosLogoIcon;
            this.pbLogo.Location = new System.Drawing.Point(27, 352);
            this.pbLogo.Margin = new System.Windows.Forms.Padding(2);
            this.pbLogo.Name = "pbLogo";
            this.pbLogo.Size = new System.Drawing.Size(100, 100);
            this.pbLogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbLogo.TabIndex = 0;
            this.pbLogo.TabStop = false;
            // 
            // btnGraph
            // 
            this.btnGraph.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnGraph.FlatAppearance.BorderSize = 0;
            this.btnGraph.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGraph.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnGraph.Image = global::Main_Panel_Controls.Properties.Resources.bar_graph_icon_;
            this.btnGraph.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnGraph.Location = new System.Drawing.Point(0, 228);
            this.btnGraph.Margin = new System.Windows.Forms.Padding(2);
            this.btnGraph.Name = "btnGraph";
            this.btnGraph.Padding = new System.Windows.Forms.Padding(9, 0, 0, 0);
            this.btnGraph.Size = new System.Drawing.Size(165, 49);
            this.btnGraph.TabIndex = 5;
            this.btnGraph.Text = "       Graph";
            this.btnGraph.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnGraph.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnGraph.UseVisualStyleBackColor = true;
            this.btnGraph.Click += new System.EventHandler(this.btnGraph_Click);
            // 
            // btnWeather
            // 
            this.btnWeather.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnWeather.FlatAppearance.BorderSize = 0;
            this.btnWeather.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnWeather.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnWeather.Image = global::Main_Panel_Controls.Properties.Resources.caution_sign_icon_;
            this.btnWeather.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnWeather.Location = new System.Drawing.Point(0, 179);
            this.btnWeather.Margin = new System.Windows.Forms.Padding(2);
            this.btnWeather.Name = "btnWeather";
            this.btnWeather.Padding = new System.Windows.Forms.Padding(9, 0, 0, 0);
            this.btnWeather.Size = new System.Drawing.Size(165, 49);
            this.btnWeather.TabIndex = 3;
            this.btnWeather.Text = "       Weather";
            this.btnWeather.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnWeather.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnWeather.UseVisualStyleBackColor = true;
            this.btnWeather.Click += new System.EventHandler(this.btnWeather_Click);
            // 
            // btnRooms
            // 
            this.btnRooms.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnRooms.FlatAppearance.BorderSize = 0;
            this.btnRooms.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnRooms.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRooms.Image = global::Main_Panel_Controls.Properties.Resources.sensor_icon_;
            this.btnRooms.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnRooms.Location = new System.Drawing.Point(0, 130);
            this.btnRooms.Margin = new System.Windows.Forms.Padding(2);
            this.btnRooms.Name = "btnRooms";
            this.btnRooms.Padding = new System.Windows.Forms.Padding(9, 0, 0, 0);
            this.btnRooms.Size = new System.Drawing.Size(165, 49);
            this.btnRooms.TabIndex = 2;
            this.btnRooms.Text = "       Rooms";
            this.btnRooms.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnRooms.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnRooms.UseVisualStyleBackColor = true;
            this.btnRooms.Click += new System.EventHandler(this.btnRooms_Click);
            // 
            // btnHome
            // 
            this.btnHome.BackColor = System.Drawing.Color.White;
            this.btnHome.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnHome.FlatAppearance.BorderSize = 0;
            this.btnHome.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnHome.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnHome.Image = global::Main_Panel_Controls.Properties.Resources.home_icon_;
            this.btnHome.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnHome.Location = new System.Drawing.Point(0, 81);
            this.btnHome.Margin = new System.Windows.Forms.Padding(2);
            this.btnHome.Name = "btnHome";
            this.btnHome.Padding = new System.Windows.Forms.Padding(9, 0, 0, 0);
            this.btnHome.Size = new System.Drawing.Size(165, 49);
            this.btnHome.TabIndex = 1;
            this.btnHome.Text = "       Home";
            this.btnHome.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnHome.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnHome.UseVisualStyleBackColor = false;
            this.btnHome.Click += new System.EventHandler(this.btnHome_Click);
            // 
            // pnLogo
            // 
            this.pnLogo.Controls.Add(this.lblGroup);
            this.pnLogo.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnLogo.Location = new System.Drawing.Point(0, 0);
            this.pnLogo.Margin = new System.Windows.Forms.Padding(2);
            this.pnLogo.Name = "pnLogo";
            this.pnLogo.Size = new System.Drawing.Size(165, 81);
            this.pnLogo.TabIndex = 0;
            // 
            // lblGroup
            // 
            this.lblGroup.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.lblGroup.BackColor = System.Drawing.Color.Transparent;
            this.lblGroup.Font = new System.Drawing.Font("Casanova Scotia", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblGroup.ForeColor = System.Drawing.Color.Black;
            this.lblGroup.Location = new System.Drawing.Point(8, 12);
            this.lblGroup.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblGroup.Name = "lblGroup";
            this.lblGroup.Size = new System.Drawing.Size(150, 59);
            this.lblGroup.TabIndex = 6;
            this.lblGroup.Text = "Group #3";
            this.lblGroup.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // pnTitle
            // 
            this.pnTitle.BackColor = System.Drawing.Color.White;
            this.pnTitle.Controls.Add(this.lbBackToHome);
            this.pnTitle.Controls.Add(this.btnMaximize);
            this.pnTitle.Controls.Add(this.btnMinimize);
            this.pnTitle.Controls.Add(this.btnClose);
            this.pnTitle.Controls.Add(this.btnBackToHome);
            this.pnTitle.Controls.Add(this.lblTitle);
            this.pnTitle.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnTitle.Location = new System.Drawing.Point(165, 0);
            this.pnTitle.Margin = new System.Windows.Forms.Padding(2);
            this.pnTitle.Name = "pnTitle";
            this.pnTitle.Size = new System.Drawing.Size(680, 81);
            this.pnTitle.TabIndex = 1;
            this.pnTitle.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pnTitle_MouseDown);
            // 
            // lbBackToHome
            // 
            this.lbBackToHome.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.lbBackToHome.AutoSize = true;
            this.lbBackToHome.Font = new System.Drawing.Font("OCR A Extended", 26.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbBackToHome.ForeColor = System.Drawing.Color.Black;
            this.lbBackToHome.Location = new System.Drawing.Point(66, 19);
            this.lbBackToHome.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lbBackToHome.Name = "lbBackToHome";
            this.lbBackToHome.Size = new System.Drawing.Size(105, 37);
            this.lbBackToHome.TabIndex = 6;
            this.lbBackToHome.Text = "Home";
            this.lbBackToHome.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lbBackToHome.Visible = false;
            // 
            // btnMaximize
            // 
            this.btnMaximize.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnMaximize.FlatAppearance.BorderSize = 0;
            this.btnMaximize.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnMaximize.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnMaximize.Location = new System.Drawing.Point(610, 2);
            this.btnMaximize.Margin = new System.Windows.Forms.Padding(2);
            this.btnMaximize.Name = "btnMaximize";
            this.btnMaximize.Size = new System.Drawing.Size(27, 33);
            this.btnMaximize.TabIndex = 5;
            this.btnMaximize.Text = "O";
            this.btnMaximize.UseVisualStyleBackColor = true;
            this.btnMaximize.Click += new System.EventHandler(this.btnMaximize_Click);
            // 
            // btnMinimize
            // 
            this.btnMinimize.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnMinimize.FlatAppearance.BorderSize = 0;
            this.btnMinimize.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnMinimize.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.World, ((byte)(0)));
            this.btnMinimize.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.btnMinimize.Location = new System.Drawing.Point(556, -1);
            this.btnMinimize.Margin = new System.Windows.Forms.Padding(2);
            this.btnMinimize.Name = "btnMinimize";
            this.btnMinimize.Size = new System.Drawing.Size(50, 30);
            this.btnMinimize.TabIndex = 4;
            this.btnMinimize.Text = "‐";
            this.btnMinimize.UseVisualStyleBackColor = true;
            this.btnMinimize.Click += new System.EventHandler(this.btnMinimize_Click);
            // 
            // btnClose
            // 
            this.btnClose.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnClose.FlatAppearance.BorderSize = 0;
            this.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnClose.Location = new System.Drawing.Point(641, 2);
            this.btnClose.Margin = new System.Windows.Forms.Padding(2);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(36, 30);
            this.btnClose.TabIndex = 3;
            this.btnClose.Text = "X";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnBackToHome
            // 
            this.btnBackToHome.BackColor = System.Drawing.Color.Transparent;
            this.btnBackToHome.Dock = System.Windows.Forms.DockStyle.Left;
            this.btnBackToHome.FlatAppearance.BorderSize = 0;
            this.btnBackToHome.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnBackToHome.Image = global::Main_Panel_Controls.Properties.Resources.double_chevron_icon_;
            this.btnBackToHome.Location = new System.Drawing.Point(0, 0);
            this.btnBackToHome.Margin = new System.Windows.Forms.Padding(2);
            this.btnBackToHome.Name = "btnBackToHome";
            this.btnBackToHome.Size = new System.Drawing.Size(81, 81);
            this.btnBackToHome.TabIndex = 2;
            this.btnBackToHome.UseVisualStyleBackColor = false;
            this.btnBackToHome.Click += new System.EventHandler(this.btnBackToHome_Click);
            // 
            // lblTitle
            // 
            this.lblTitle.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("OCR A Extended", 26.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.ForeColor = System.Drawing.Color.Black;
            this.lblTitle.Location = new System.Drawing.Point(268, 19);
            this.lblTitle.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(105, 37);
            this.lblTitle.TabIndex = 1;
            this.lblTitle.Text = "Home";
            this.lblTitle.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // pnDesktop
            // 
            this.pnDesktop.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnDesktop.Location = new System.Drawing.Point(165, 81);
            this.pnDesktop.Margin = new System.Windows.Forms.Padding(2);
            this.pnDesktop.MinimumSize = new System.Drawing.Size(680, 393);
            this.pnDesktop.Name = "pnDesktop";
            this.pnDesktop.Size = new System.Drawing.Size(680, 393);
            this.pnDesktop.TabIndex = 1;
            // 
            // MainPanel
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(845, 474);
            this.Controls.Add(this.pnDesktop);
            this.Controls.Add(this.pnTitle);
            this.Controls.Add(this.pnMenu);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.MinimumSize = new System.Drawing.Size(860, 510);
            this.Name = "MainPanel";
            this.Text = "MainPanel";
            this.Load += new System.EventHandler(this.MainPanel_Load);
            this.pnMenu.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pbLogo)).EndInit();
            this.pnLogo.ResumeLayout(false);
            this.pnTitle.ResumeLayout(false);
            this.pnTitle.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel pnMenu;
        private System.Windows.Forms.Button btnGraph;
        private System.Windows.Forms.Button btnWeather;
        private System.Windows.Forms.Button btnRooms;
        private System.Windows.Forms.Button btnHome;
        private System.Windows.Forms.Panel pnLogo;
        private System.Windows.Forms.Panel pnTitle;
        private System.Windows.Forms.Panel pnDesktop;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.Button btnBackToHome;
        private System.Windows.Forms.Button btnMaximize;
        private System.Windows.Forms.Button btnMinimize;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.PictureBox pbLogo;
        private System.Windows.Forms.Label lblGroup;
        private System.Windows.Forms.Label lbBackToHome;
    }
}

