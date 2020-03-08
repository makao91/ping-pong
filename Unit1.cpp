//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8;
int z = -8;
int c = -8;
int player1score = 0;
int player2score = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        ShowMessage("Witaj w grze o ¿ycie! \n \n Twoim celem jest nie daæ zaraziæ siê koronawirusem! \n Lewy gracz steruje klawiszami Z oraz X. \n Prawy gracz steruje strza³kami góra i dó³. \n \n Wa¿na informacja: gdy wirus odbija siê od kolorowych koñców, przyspiesza i zmienia k¹t poruszania sie. \n Trzy wirusy wystarcz¹ by ciê zaraziæ! \n \n Udanej zabawy!");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::top1Timer(TObject *Sender)
{
      if(p1->Top > 10) p1->Top += -10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::down1Timer(TObject *Sender)
{
       if(p1->Top + p1->Height < tlo->Height -10) p1->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 0x5A)  top1->Enabled=true;
        if(Key == 0x58)  down1->Enabled=true;
        if(Key == VK_UP)  top2->Enabled=true;
        if(Key == VK_DOWN)  down2->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
       if(Key == 0x5A)  top1->Enabled=false;
        if(Key == 0x58)  down1->Enabled=false;
        if(Key == VK_UP)  top2->Enabled=false;
        if(Key == VK_DOWN)  down2->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::top2Timer(TObject *Sender)
{
      if(p2->Top > 10) p2->Top += -10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::down2Timer(TObject *Sender)
{
      if(p2->Top + p2->Height < tlo->Height -10) p2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ballTTimer(TObject *Sender)
{
      ball->Left+=x;
      ball->Top+=y;

      //odbij od górnej sciany
       if(ball->Top-5 <= 0) y = -y;

       //odbij od dolnej
       if(ball->Top >= tlo->Height-30) y = -y;

       //fail
       if((ball->Left <= 0))
       {
                ballT->Enabled = false;
                capsule1->Enabled = false;
                capsule2->Enabled = false;
                ball->Visible = false;
                Button1->Caption = "Skucha!";
                Button1->Visible = true;
                player2score++;
                score2->Caption =  player2score;
                x=-8;
                if(player2score ==3)
                {

                  Button2->Caption = "Wygrywa gracz prawy!";
                  Button2->Visible = true;
                  Button1->Caption = "Again?";
                 player1score = 0;
                 player2score = 0;
                 score1->Caption =  player1score;
                 score2->Caption =   player2score;
                }
       }
       else if(ball->Left >= tlo->Width-15)
       {
                ballT->Enabled = false;
                capsule1->Enabled = false;
                capsule2->Enabled = false;
                ball->Visible = false;
                Button1->Caption = "Skucha!";
                Button1->Visible = true;
                player1score++;
                score1->Caption =  player1score;
                 if(player1score ==3)
                {

                  Button2->Caption = "Wygrywa gracz lewy!";
                  Button2->Visible = true;
                  Button1->Caption = "Again?";
                 player1score = 0;
                 player2score = 0;
                 score1->Caption =  player1score;
                 score2->Caption =   player2score;
                }
       }

       else if ((ball->Top >= p1->Top - ball->Height/2) && (ball->Top + ball->Height <= p1->Top + p1->Height + ball->Height/2) && (ball->Left < p1->Left + p1->Width+5 ) )
        {
                if((ball->Top >= (p1->Top + p1->Height-57)) && (ball->Top + ball->Height <= p1->Top + p1->Height + ball->Height/2))
                {
                  if (x<0)
                  {
                        x=-x;
                        x+=2;
                  }
                }
                else if((ball->Top >= p1->Top - ball->Height/2) && (ball->Top + ball->Height <= p1->Top + 57))
                {
                  if (x<0)
                  {
                        x=-x;
                        x+=2;
                  }
                }
                else
                {
                        if(x<0) {x=-x; y=8; }
                }
        }

        else if ((ball->Top >= p2->Top - ball->Height/2) && (ball->Top + ball->Height <= p2->Top + p2->Height + ball->Height/2) && (ball->Left + ball->Width >= p2->Left ) )
        {
                if((ball->Top >= (p2->Top + p2->Height-57)) && (ball->Top + ball->Height <= p2->Top + p2->Height + ball->Height/2))
                {
                  if (x>0)
                  {
                        x=-x;
                         x-=2;
                  }
                }
                else if((ball->Top >= p2->Top - ball->Height/2) && (ball->Top + ball->Height <= p2->Top + 57))
                {
                 if (x>0)
                  {
                        x=-x;
                         x-=2;
                  }
                }
                else
                {
                if(x>0) {x=-x; y=8; }
                }
        }

       else if  ((ball->Top >= cap1->Top + ball->Width/2) && (ball->Top + ball->Height <= cap1->Top + cap1->Height+ ball->Width/2 ) && (ball->Left <= cap1->Left + cap1->Width)&& (ball->Left + ball->Width >= cap1->Left + cap1->Width - 10))
        {
                if(x<0)  x=-x;
        }
        else if ((ball->Top >= cap1->Top+ ball->Width/2) && (ball->Top + ball->Height <= cap1->Top + cap1->Height+ ball->Width/2 ) && (ball->Left + ball->Width >= cap1->Left) && (ball->Left <= cap1->Left + 10) )
        {
                if(x>0)  x=-x;
        }
        else if ((ball->Top >= cap2->Top + ball->Width/2 ) && (ball->Top + ball->Height <= cap2->Top + cap2->Height+ ball->Width/2) && (ball->Left <= cap2->Left + cap2->Width)&& (ball->Left + ball->Width >= cap2->Left + cap1->Width - 10))
        {
                if(x<0)  x=-x;
        }
        else if ((ball->Top >= cap2->Top + ball->Width/2 ) && (ball->Top + ball->Height <= cap2->Top + cap2->Height+ ball->Width/2) && (ball->Left + ball->Width > cap2->Left) && (ball->Left <= cap2->Left + 10) )
        {
               if(x>0)  x=-x;
        }   
}
//---------------------------------------------------------------------------


void __fastcall TForm1::capsule1Timer(TObject *Sender)
{
        cap1->Top += z;
      if(cap1->Top - 2 <= 0)
      {
         z = -z;
      }
      if(cap1->Top + cap1->Height + 2 >= tlo->Height)
      {
        z = -z;
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::capsule2Timer(TObject *Sender)
{
    cap2->Top += c;
      if(cap2->Top - 2 <= 0) c = -c;
      if(cap2->Top + cap2->Height >= tlo->Height) c = -c;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  p1->Top = 120;
  p2->Top = 120;

  ball->Left = 560;
  ball->Top = 400;
  cap1->Top = 64;
  cap2->Top = 272;
  ballT->Enabled = true;
  capsule1->Enabled = true;
  capsule2->Enabled = true;
  ball->Visible = true;
  Button1->Visible = false;
  Button2->Visible = false;
  x=-8;
    p1->Left = 16;
    p2->Left = tlo->Width-37;
    cap1->Left = 300;
    cap2->Left = tlo->Width-337;
    Button1->Left = tlo->Width/2 -64;
    Button2->Left = tlo->Width/2 -64;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    ballT->Enabled = false;
    capsule1->Enabled = false;
    capsule2->Enabled = false;
    score1->Visible = false;
    score2->Visible = false;
    line->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    ballT->Enabled = true;
    capsule1->Enabled = true;
    capsule2->Enabled = true;
    score1->Visible = true;
    score2->Visible = true;
    line->Visible = true;
    Label1->Visible = false;
    Label2->Visible = false;
    Button3->Visible = false;
    p1->Left = 16;
    p2->Left = tlo->Width-37;
    cap1->Left = 300;
    cap2->Left = tlo->Width-337;
    Button1->Left = tlo->Width/2 -64;
    Button2->Left = tlo->Width/2 -64;

}
//---------------------------------------------------------------------------


