using System;
using System.Drawing;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace indoor_climate_control_application
{
    public partial class MainPanel : Form
    {
        private Button currentClickedButton;

        private Form currentActiveForm;
        private Form HomeForm;
        private Form RoomsForm;
        private Form WeatherForm;
        private Form DatabaseForm;

        public MainPanel()
        {
            InitializeComponent();
            FormBorderStyle = FormBorderStyle.None;
            HomeForm = new subForms.Home();
            RoomsForm = new subForms.Rooms();
            WeatherForm = new subForms.Weather();
            DatabaseForm = new subForms.Database();
        }

        [DllImport("user32.DLL", EntryPoint = "ReleaseCapture")]
        private extern static void ReleaseCapture();
        [DllImport("user32.DLL", EntryPoint = "SendMessage")]
        private extern static void SendMessage(System.IntPtr hWnd, int wMsg, int wParam, int lParam);
        private void MainPanel_Load(object sender, EventArgs e)
        {
            OpenSubForm(HomeForm);
        }

        private void OpenSubForm(Form subForm)
        {
            currentActiveForm = subForm;
            subForm.BackColor = Color.White;
            subForm.TopLevel = false;
            subForm.FormBorderStyle = FormBorderStyle.None;
            subForm.Dock = DockStyle.Fill;
            ViewFormPanel.Controls.Add(subForm);
            ViewFormPanel.Tag = subForm;
            subForm.BringToFront();
            subForm.Show();
            TitleLabel.Text = subForm.Text;
        }
        private Color SelectThemeColor(Form subForm) 
        {
            Color formColour = Color.LightGray;

            if (subForm == HomeForm)
            {
                formColour = Color.GhostWhite;
            }
            else if (subForm == RoomsForm)
            {
                formColour = Color.GreenYellow;
            }
            else if (subForm == DatabaseForm)
            {
                formColour = Color.LightBlue;
            }
            else if (subForm == WeatherForm)
            {
                formColour = Color.LightCoral;
            }
            return formColour;
        }
        private void SelectForm(object clickedButton, Form subForm)
        {
            if (clickedButton != null)
            {
                if (currentClickedButton != clickedButton as Button)
                {
                    DeClickedButton();
                    Color colour = SelectThemeColor(subForm);
                    currentClickedButton = clickedButton as Button;
                    if (currentClickedButton != null)
                    {
                        ClickedButton(colour);
                    }
                }
            }
        }

        private void ClickedButton(Color colour)
        {
            currentClickedButton.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 10.8F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));

            currentClickedButton.BackColor = colour;

            ButtonPanel.BackColor = colour;
            LogoPanel.BackColor = colour;
            TitlePanel.BackColor = colour;
        }

        private void DeClickedButton()
        {
            foreach (Control uiObject in ButtonPanel.Controls)
            {
                if (uiObject.GetType() == typeof(Button))
                {
                    uiObject.BackColor = Color.Transparent;
                    uiObject.ForeColor = Color.Black;
                    uiObject.Font = new System.Drawing.Font("Yu Gothic UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                }
            }
        }

        private void HandleSelectedMenu(Form subForm, object clickedButton)
        {
            if (currentActiveForm != null)
            {
                currentActiveForm.Hide();
            }
            SelectForm(clickedButton, subForm);
            OpenSubForm(subForm);
        }

        private void HomeFormButton_Click(object sender, EventArgs e)
        {
            HandleSelectedMenu(HomeForm, sender);
        }

        private void RoomsFormButton_Click(object sender, EventArgs e)
        {
            HandleSelectedMenu(RoomsForm, sender);
        }

        private void WeatherFormButton_Click(object sender, EventArgs e)
        {
            HandleSelectedMenu(WeatherForm, sender);
        }

        private void DatabaseFormButton_Click(object sender, EventArgs e)
        {
            HandleSelectedMenu(DatabaseForm, sender);
        }

        private void ExitButton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void WindowButton_Click(object sender, EventArgs e)
        {
            WindowState = (WindowState == FormWindowState.Normal) ? FormWindowState.Maximized : FormWindowState.Normal; 
        }

        private void MinimizeButton_Click(object sender, EventArgs e)
        {
            WindowState = FormWindowState.Minimized;
        }

        private void TitlePanel_MouseDown(object sender, MouseEventArgs e)
        {
            ReleaseCapture();
            SendMessage(this.Handle, 0x112, 0xf012, 0);
        }

        private void LogoPanel_MouseDown(object sender, MouseEventArgs e)
        {
            ReleaseCapture();
            SendMessage(this.Handle, 0x112, 0xf012, 0);
        }

        private void LogoBox_MouseDown(object sender, MouseEventArgs e)
        {
            ReleaseCapture();
            SendMessage(this.Handle, 0x112, 0xf012, 0);
        }

        private void TitleLabel_MouseDown(object sender, MouseEventArgs e)
        {
            ReleaseCapture();
            SendMessage(this.Handle, 0x112, 0xf012, 0);
        }
    }
}
