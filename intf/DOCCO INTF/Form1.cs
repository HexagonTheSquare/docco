using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DOCCO_INTF
{
    public partial class Form1 : Form
    {
        List<Panel> panelList = new List<Panel>();

        public Form1()
        {
            InitializeComponent();
            serialPort1.Open();
            serialPort1.WriteTimeout = 10000;

            panelList.Add(panel1);
            panelList.Add(panel2);
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            string positionOutput = "P " +
                $"{thumbTrack.Value} {indexTrack.Value} {middleTrack.Value} {ringTrack.Value} {pinkyTrack.Value}";

            serialPort1.Write(positionOutput);
        }

        private void submitButton_Click(object sender, EventArgs e)
        {
            string setupOutput = "S " +
                $"{thumbServo1.Text} {thumbServo2.Text} {thumbServo3.Text} " +
                $"{indexServo1.Text} {indexServo2.Text} {indexServo3.Text} " +
                $"{middleServo1.Text} {middleServo2.Text} {middleServo3.Text} " +
                $"{ringServo1.Text} {ringServo2.Text} {ringServo3.Text} " +
                $"{pinkyServo1.Text} {pinkyServo2.Text} {pinkyServo3.Text}";

            serialPort1.Write(setupOutput);
            panelList[0].BringToFront();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            panelList[1].BringToFront();
        }

        private void middleButton_Click_1(object sender, EventArgs e)
        {
            thumbTrack.Value = 0;
            indexTrack.Value = 0;
            middleTrack.Value = 90;
            ringTrack.Value = 0;
            pinkyTrack.Value = 0;
        }

        private void peaceButton_Click_1(object sender, EventArgs e)
        {
            thumbTrack.Value = 0;
            indexTrack.Value = 90;
            middleTrack.Value = 90;
            ringTrack.Value = 0;
            pinkyTrack.Value = 0;
        }

        private void broButton_Click_1(object sender, EventArgs e)
        {
            thumbTrack.Value = 90;
            indexTrack.Value = 0;
            middleTrack.Value = 0;
            ringTrack.Value = 0;
            pinkyTrack.Value = 90;
        }

        private void rockButton_Click_1(object sender, EventArgs e)
        {
            thumbTrack.Value = 0;
            indexTrack.Value = 90;
            middleTrack.Value = 0;
            ringTrack.Value = 0;
            pinkyTrack.Value = 90;
        }

        private void spiderButton_Click_1(object sender, EventArgs e)
        {
            thumbTrack.Value = 90;
            indexTrack.Value = 90;
            middleTrack.Value = 0;
            ringTrack.Value = 0;
            pinkyTrack.Value = 90;
        }

        private void thumbButton_Click_1(object sender, EventArgs e)
        {
            thumbTrack.Value = 90;
            indexTrack.Value = 0;
            middleTrack.Value = 0;
            ringTrack.Value = 0;
            pinkyTrack.Value = 0;
        }
    }
}
