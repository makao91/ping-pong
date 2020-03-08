//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *tlo;
        TImage *p2;
        TTimer *top1;
        TTimer *down1;
        TTimer *top2;
        TTimer *down2;
        TImage *ball;
        TTimer *ballT;
        TButton *Button1;
        TImage *p1;
        TImage *cap1;
        TImage *cap2;
        TTimer *capsule1;
        TTimer *capsule2;
        void __fastcall top1Timer(TObject *Sender);
        void __fastcall down1Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall top2Timer(TObject *Sender);
        void __fastcall down2Timer(TObject *Sender);
        void __fastcall ballTTimer(TObject *Sender);
        void __fastcall capsule1Timer(TObject *Sender);
        void __fastcall capsule2Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
