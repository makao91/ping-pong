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

      //odbij od górnej sciany
       if(ball->Top-5 <= 0) y = -y;

       //odbij od dolnej
       if(ball->Top >= tlo->Height-30) y = -y;

       //fail
       if((ball->Left == 0) || (ball->Left >= tlo->Width-25))
       {
                ballT->Enabled = false;
                ball->Visible = false;
                Button1->Caption = "Przegra³es!";
                Button1->Visible = true;

       }
       else if ((ball->Top <= (p1->Top + p1->Height + ball->Height/2)) && (ball->Top >= p1->Top - ball->Height/4) && (ball->Left < p1->Left + p1->Width))
        {
                x=-x;
        }
        else if ((ball->Top <= (p2->Top + p2->Height + ball->Height/2)) && (ball->Top >= p2->Top - ball->Height/4) && (ball->Left > p2->Left - p2->Width - 15))
        {
                x=-x;
        }

}
//---------------------------------------------------------------------------
