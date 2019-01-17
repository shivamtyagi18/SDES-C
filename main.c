
#include<stdio.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
// function prototype, also called function declaration
//-------------------------------------------------------------------------------------
//----------------------------------------P10 permutation and Subkey Generation------------------------------------------
//-------------------------------------------------------------------------------------

char alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int Per10 ( int pt[8], int key[10], int P10[10] )   // function definition
{
    int p10[10]={key[2],key[4],key[1],key[6],key[3],key[9],key[0],key[8],key[7],key[5]};
    
    for (int i=0;i<=9;i++) {
        
        P10[i]=p10[i];//permuted key p10
    }
    
    printf("\n");
    return 0 ;
    
}
//-------------------------------------------------------------------------------------
//---------------------Subkey Generation----------------------------------------------------------------------
//-------------------------------------------------------------------------------------
int Subkeys ( int P10[10], int Subkey1[8], int Subkey2[8] )   // function definition
{
    
    int ls1[10]={P10[1],P10[2],P10[3],P10[4],P10[0],P10[6],P10[7],P10[8],P10[9],P10[5]}; // left shift 1 p10
    
    //-------------------------------------------------------------------------------------
    int subkey1[8]={ls1[5],ls1[2],ls1[6],ls1[3],ls1[7],ls1[4],ls1[9],ls1[8]};
    
    for (int i=0;i<=7;i++) {
        
        Subkey1[i]=subkey1[i];  //subkey 1
    }
    
    
    //-------------------------------------------------------------------------------------
    int ls2[10]={P10[3],P10[4],P10[0],P10[1],P10[2],P10[8],P10[9],P10[5],P10[6],P10[7]};  //left shift 3 p10
    
    //-------------------------------------------------------------------------------------
    int subkey2[8]={ls2[5],ls2[2],ls2[6],ls2[3],ls2[7],ls2[4],ls2[9],ls2[8]};
    
    for (int i=0;i<=7;i++) {
        
        Subkey2[i]=subkey2[i];  //subkey 2
    }
    
    return 0 ;
    
}
//-------------------------------------------------------------------------------------
//-------------initial permutation------------------------------------------------
//-------------------------------------------------------------------------------------
int IPer( int pt[8], int IP[10] )
{
    int ip[8]={pt[1],pt[5],pt[2],pt[0],pt[3],pt[7],pt[4],pt[6]};
    
    for (int i=0;i<=7;i++) {
        
        IP[i]=ip[i];  //initial permutation of plaintext
    }
    
    
    return 0;
}
//-------------------------------------------------------------------------------------
//-------------inverse permutation------------------------------------------------
//-------------------------------------------------------------------------------------
int InvPer( int fk2[8], int InvP[10] )
{
    
    int ip1[8]={fk2[3],fk2[0],fk2[2],fk2[4],fk2[6],fk2[1],fk2[7],fk2[5]};
    
    for (int i=0;i<=7;i++) {
        
        InvP[i]=ip1[i];  //inverese permutation
    }
    
    
    return 0;
}
//-------------------------------------------------------------------------------------
//---------------------E/P--------------------------------------------------
//-------------------------------------------------------------------------------------
int EPer(int IP[10], int EP[8],int FKL[4], int FKR[4])
{
    
    int fk1R[4]={IP[4],IP[5],IP[6],IP[7]};
    
    int fk1L[4]={IP[0],IP[1],IP[2],IP[3]};
    
    for (int i=0;i<=3;i++) {
        
        FKL[i]=fk1L[i];  //fk1L
    }
    for (int i=0;i<=3;i++) {
        
        FKR[i]=fk1R[i];  //fk1R
    }
    
    int ep[8]={fk1R[3],fk1R[0],fk1R[1],fk1R[2],fk1R[1],fk1R[2],fk1R[3],fk1R[0]};
    
    for (int i=0;i<=7;i++) {
        
        EP[i]=ep[i];  //  E/P
    }
    
    return 0;
}

//-------------------------------------------------------------------------------------
//---------------SBOX Processing--------------------------------------------------------
//-------------------------------------------------------------------------------------

int SBOXES( int S[8], int Z[4])
{
    //int IP[10],EP[8],FKL[4],FKR[4];
    
    // EPer(IP,EP,S,FKL,FKR);
    
    int SBOX0[4][4]={{0b01,0b00,0b11,0b10},{0b11,0b10,0b01,0b00},{0b00,0b10,0b01,0b11},{0b11,0b01,0b11,0b10}};
    
    int SBOX1[4][4]={{0b00,0b01,0b10,0b11},{0b10,0b00,0b01,0b11},{0b11,0b00,0b01,0b00},{0b10,0b01,0b00,0b11}};
    
    
    int x=2*S[0] + S[3];
    
    int y=2*S[1]+S[2];
    
    //printf("%d%d",x,y);
    
    printf("\n");
    
    int z[1][1]={SBOX0[x][y]};
    
    //printf("%d",z[0][0]);
    
    printf("\n");
    
    
    int x1=2*S[4]+S[7];
    
    int y1=2*S[5]+S[6];
    
    //printf("%d%d",x1,y1);
    
    printf("\n");
    
    int z1[1][1]={SBOX1[x1][y1]};
    
    //printf("%d",z1[0][0]);
    
    
    int A[4]={(z[0][0])/2,(z[0][0])%2,z1[0][0]/2,z1[0][0]%2};
    
    for (int i=0;i<=3;i++) {
        
        Z[i]=A[i];  // Output of SBoxes
        
    }
    
    
    return 0;
}
//-------------------------------------------------------------------------------------
//------------------P4 Permutation--------------------------------
//-------------------------------------------------------------------------------------
int Per4( int P4[4], int Z[4])
{
    
    int p4[4]={Z[1],Z[3],Z[2],Z[0]};
    
    for (int i=0;i<=3;i++) {
        
        P4[i]=p4[i];  // Output of SBoxes
        
    }
    
    return 0;
}
//-------------------------------------------------------------------------------------
//------------------------fk output-----------------------------------
//-------------------------------------------------------------------------------------
int fk(int FKR[4], int fk1[8])
{
    for (int i=4;i<=7;i++) {
        fk1[i]=FKR[i-4];
    }
    
    return 0;
}
//-------------------------------------------------------------------------------------
//------------------------Switch Function-----------------------------------
//-------------------------------------------------------------------------------------

int SWTCH(int fk1[8], int swtch[8])
{
    
    for (int i=0;i<=3;i++) {
        swtch[i]=fk1[i+4];
    }
    
    for (int i=4;i<=7;i++) {
        swtch[i]=fk1[i-4];
    }
    
    return 0;
}
//-------------------------------------------------------------------------------------
//--------------------------Encryption function----------------------------------------------
//-------------------------------------------------------------------------------------

int Encryption(int pt[8], int key[10] )
{
    //int pt[8] ={1,1,0,1,0,1,0,1};
    // int key[10]={0,1,1,1,0,1,0,0,0,1};
    int P10[10],Subkey1[8],Subkey2[8],IP[8],EP[8],EP1[8],S[8],S1[8],Z[4],Z1[4],fk1[8],fk11[8],swtch[8],InvP[8];
    int P4[4],P41[4]; int FKL[4],FKL1[4],FKR[4],FKR1[4];
    
    
    
    printf("Plain Text is ");
    
    for(int i=0;i<=7;i++)
    {
        printf("%d",pt[i]);
    }
    
    printf("\n");
    
   
    
    printf("Key is ");
    for(int i=0;i<=9;i++)
    {
        printf("%d",key[i]);
    }
    
    printf("\n");
    
    Per10(pt,key,P10) ; //calling Permutation function
    
    Subkeys(P10,Subkey1,Subkey2); //calling Subkey function
    
    IPer(pt,IP); //calling Initial Permutation function
    
    EPer(IP,EP,FKL,FKR); //Expansion and permutation function--------------------
    
    for (int i=0;i<=7;i++) {
        
        S[i]=EP[i]^Subkey1[i];//Xoring EP with subkey 1 to find S----
    }
    
    SBOXES(S,Z);  //caliing SBOX function-----------------
    
    Per4(P4,Z); //------calling Per4 function---------
    
    for (int i=0;i<=3;i++) {
        fk1[i]=P4[i]^FKL[i]; // Xoring P4 and FKL
    }
    
    fk(FKR,fk1);  //calling function fk-----------------
    
    SWTCH(fk1,swtch);
    
    EPer(swtch,EP1,FKL1,FKR1); //Expansion and permutation function--------------------
    
    for (int i=0;i<=7;i++) {
        
        S1[i]=EP1[i]^Subkey2[i];//Xoring EP1 with subkey 2 to find S1----
            }
    
    SBOXES(S1,Z1);  //caliing SBOX function-----------------
    
    Per4(P41,Z1); //------calling Per4 function---------
    
    for (int i=0;i<=3;i++) {
        fk11[i]=P41[i]^FKL1[i]; // Xoring P41 and FKL1
    }
    
    fk(FKR1,fk11);  //calling function fk-----------------
    
    InvPer(fk11,InvP);
    
    printf("\nInvP Cipher Text is --");
    for (int i=0;i<=7;i++) {
        
        printf("%d",InvP[i]);  //  final output
    }
    
    printf("\n");
    
    printf("Alphabets are :  ");
    
    int x = 8*InvP[0]+4*InvP[1]+2*InvP[2]+InvP[3];
    printf("%c",alphabet[x]);
    
    int y = 8*InvP[4]+4*InvP[5]+2*InvP[6]+InvP[7];
    printf("%c",alphabet[y]);
    
    printf("\n");
    
    return 0;
}
//----------------------------------------------------------------------------------------------------
//------------------------------------Decryption----------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
int Decryption(int pt[8], int key[10])
{
    //int pt[8] ={0,1,1,1,0,0,1,1};
    // int key[10]={0,1,1,1,0,1,0,0,0,1};
    int P10[10],Subkey1[8],Subkey2[8],IP[8],EP[8],EP1[8],S[8],S1[8],Z[4],Z1[4],fk1[8],fk11[8],swtch[8],InvP[8];
    int P4[4],P41[4]; int FKL[4],FKL1[4],FKR[4],FKR1[4];
    
    
    printf("Cipher Text is ");
    
    for(int i=0;i<=7;i++)
    {
        printf("%d",pt[i]);
    }
    
    printf("\n");
    
    printf("Key is ");
    
    for(int i=0;i<=9;i++)
    {
        printf("%d",key[i]);
    }
    
    printf("\n");
    
    Per10(pt,key,P10) ; //calling Permutation function
    
    Subkeys(P10,Subkey1,Subkey2); //calling Subkey function
    
    IPer(pt,IP); //calling Initial Permutation function
    
    EPer(IP,EP,FKL,FKR); //Expansion and permutation function--------------------
    
    for (int i=0;i<=7;i++) {
        
        S[i]=EP[i]^Subkey2[i];//Xoring EP with subkey 2 to find S----
    }
    
    SBOXES(S,Z);  //caliing SBOX function-----------------
    
    Per4(P4,Z); //------calling Per4 function---------
    
    for (int i=0;i<=3;i++) {
        fk1[i]=P4[i]^FKL[i]; // Xoring P4 and FKL
    }
    
    fk(FKR,fk1);  //calling function fk-----------------
    
    SWTCH(fk1,swtch);
    
    EPer(swtch,EP1,FKL1,FKR1); //Expansion and permutation function--------------------
    
    for (int i=0;i<=7;i++) {
        
        S1[i]=EP1[i]^Subkey1[i];//Xoring EP1 with subkey 1 to find S1----
            }
    
    SBOXES(S1,Z1);  //caliing SBOX function-----------------
    
    Per4(P41,Z1); //------calling Per4 function---------
    
    for (int i=0;i<=3;i++) {
        fk11[i]=P41[i]^FKL1[i]; // Xoring P4 and FKL1
    }
    
    fk(FKR1,fk11);  //calling function fk-----------------
    
    InvPer(fk11,InvP);
    
    printf("\nInvP Plain Text is--");
    for (int i=0;i<=7;i++) {
        
        printf("%d",InvP[i]);  //  final output
    }
    
    printf("\n");
    printf("Alphabets are :  ");
    
    int x = 8*InvP[0]+4*InvP[1]+2*InvP[2]+InvP[3];
    printf("%c",alphabet[x]);
    
    int y = 8*InvP[4]+4*InvP[5]+2*InvP[6]+InvP[7];
    printf("%c",alphabet[y]);
    
    
    printf("\n");
    
    return 0;
}

// main function, program starts from here
//----------------------------------------------------------------------------------------------------
//----------------------------------Main Function------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
int main()
{
    int pt[8],key[10];
    
    int choice;
    
    
    printf("enter plain text/cipher text \n");
    for(int i=0;i<=7;i++)
    {
        scanf("%d",&pt[i]);
    }
    for(int i=0;i<=7;i++)
    {
        printf("%d",pt[i]);
    }
    
    printf("\n");
    
    printf("enter key \n");
    for(int i=0;i<=9;i++)
    {
        scanf("%d",&key[i]);
    }
    for(int i=0;i<=9;i++)
    {
        printf("%d",key[i]);
    }
    
    printf("\n");
    printf("enter choice--1 for Encryption and 2 for Decryption\n");
    scanf("%d",&choice);
    
    if (choice==1)
    { Encryption(pt,key); }
    else if (choice==2)
    { Decryption(pt,key) ; }
    
    int g;
    printf("\n");
    printf("enter any key for exit\n");
    scanf("%d",&g);
    
    
    return 0;
}
