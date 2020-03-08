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
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
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

      //odbij od g�rnej sciany
       if(ball->Top-5 <= 0) y = -y;

       //odbij od dolnej
       if(ball->Top >= tlo->Height-30) y = -y;

       //fail
       if((ball->Left <= 0) || (ball->Left >= tlo->Width-15))
       {
                ballT->Enabled = false;
                ball->Visible = false;
                Button1->Caption = "Przegra�es!";
                Button1->Visible = true;

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

