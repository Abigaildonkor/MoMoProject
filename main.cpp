#include <iostream>
#include <fstream>

using namespace std;

/************************/
/*Functions Declared below the main Function*/

void TranferMoney();
void enterNumber();
void confirmNumber();
void enterAmount();
void EnterReference();
void Rec_dets(string RecieverNum, float amount, string reffe);
void OtherNetwork();
void MoMoPay();
void Airtime();
void Cashout();
void FinanService();
void MyWallet();
void checkBalance();
void printBalance(float balance);
void Main_Menu();
void changeReset();

/*Functions Declared below the main Function*/
/************************/




int main()
{
    //making the ifstream object file to help us store and access the balance and MoMo Pin from separate txt files.
    ifstream readFunc;
    ofstream writeFunc;


    string Default_Pin = "0000",Phone_Number,conf_Phone_Number,reff,MoMoPIN;
    int input, counter = 0;
    float Money, SendAmount, Default_balance;

    readFunc.open("balance.txt");
    readFunc >> Default_balance;
    readFunc.close();



    // the wile is used to loop back into the menu
    while(counter != 3){

        //display the main Menu
        Main_Menu();

        // Receive User Input
        cin >> input;

        //Checking Input Validity
        if(input == 1){
            int x=0;
            while( x !=3){
                TranferMoney();
                cin >> input;
                if(input == 1){
                    int z = 0;
                    while(z<3){
                        enterNumber();
                        cin>>Phone_Number;
                        confirmNumber();
                        cin>>conf_Phone_Number;

                        int LengthOfNum1,LengthOfNum2;
                        LengthOfNum1 = Phone_Number.length();
                        LengthOfNum2 = conf_Phone_Number.length();

                        int Phone_NumberInt = stoi(Phone_Number);
                        int conf_Phone_NumberInt = stoi(conf_Phone_Number);

                        if((Phone_Number == conf_Phone_Number)&& (LengthOfNum1==10) && (LengthOfNum2==10)){
                            enterAmount();
                            cin>>SendAmount;
                            if((SendAmount>Default_balance)||(SendAmount<0)){
                                cout<<"Try Again Later"<<endl;
                            }
                            else{
                                EnterReference();
                                cin>>reff;
                                int u = 0;
                                Rec_dets("Ohenewaa ",SendAmount,reff);
                                while(u<3){
                                    cin>>MoMoPIN;
                                    if(MoMoPIN == Default_Pin){
                                        Default_balance -= SendAmount;
                                        cout<<"\nCurrent Balance is GHS "<<Default_balance<<endl;
                                        cout<<"Available Balance is GHS "<<Default_balance<<endl;

                                        writeFunc.open("balance.txt");
                                        writeFunc << Default_balance;
                                        writeFunc.close();

                                        return Default_balance;
                                        u = 3;
                                    }
                                    else{
                                        cout<<"Wrong Pin, Try Again"<<endl;
                                        u++;
                                    }
                                }

                            }
                            z=3;
                        }
                        else{
                            cout<<"Wrong Phone Number or its not Up to 10 Digits"<<endl;
                            z++;
                        }

                    }
                    x=3;
                }
                else if(input == 2){
                   cout<<"2"<<endl;
                    x=3;
                }
                else if(input == 3){
                    cout <<"3"<<endl;
                    x=3;
                }
                else if(input == 4){
                    cout <<"4"<<endl;
                    x=3;
                }
                else if(input == 5){
                    OtherNetwork();

                    x=3;
                }
                else if(input == 6){
                    cout <<"6"<<endl;
                    x=3;
                }
                else if(input == 0){
                    x=3;
                    main();
                }
                else{
                    cout<<"Invalid Input"<<endl;
                    x ++;
                }
            }
            break;
        }
        else if(input == 2){
            MoMoPay();
            break;
        }
        else if(input == 3){
            Airtime();
            break;
        }
        else if(input == 4){
            Cashout();
            break;
        }
        else if(input == 5){
            FinanService();
            break;
        }
        else if(input == 6){
            int h = 0;
            while(h!=3){
                MyWallet();
                int inputT;
                cin >> inputT;
                if(inputT==1){

                    string inputPin;
                    int tt=0;

                    while(tt < 3){

                        checkBalance();
                        cin>>inputPin;

                        readFunc.open("MoMoPIN.txt");
                        string checkPin;
                        getline(readFunc,checkPin);
                        readFunc.close();
                        if(inputPin == checkPin){
                            printBalance(Default_balance);
                            tt = 3;
                        }
                        else{
                            cout<<"Wrong Pin, Please Try Again"<<endl;
                            tt++;
                        }
                    }
                    h=3;
                }
                else if(inputT==2){
                    cout<<"2"<<endl;
                    h=3;
                }
                else if(inputT==3){
                    cout<<"3"<<endl;
                    h=3;
                }
                else if(inputT==4){
                    cout<<"4"<<endl;
                    h=3;
                }
                else if(inputT==5){
                    cout<<"5"<<endl;
                    h=3;
                }
                else if(inputT==6){
                    int take,l=0;
                    while (l<3){
                        changeReset();
                        cin>>take;
                        if(take == 1){

                            int j=0,inp;

                            while(j<3){

                                cout<<"\nAre you sure you want to change your MoMo PIN ?"<<endl;
                                cout<<"1) YES"<<endl;
                                cout<<"2) NO\n"<<endl;
                                cin>>inp;
                                if(inp == 1){
                                    cout<<"\nPlease Enter your Current MoMo PIN\n"<<endl;
                                    string momoCheck,realPin;
                                    cin >> momoCheck;

                                    readFunc.open("MoMoPIN.txt");
                                    readFunc >> realPin;
                                    readFunc.close();

                                    if (momoCheck == realPin){
                                        cout<<"\nPlease Enter New MoMo PIN\n"<<endl;
                                        string NewPin, NewPinCheck;
                                        cin>>NewPin;
                                        cout <<"\nPlease Re-Enter New MoMo PIN\n"<<endl;
                                        cin >> NewPinCheck;

                                        if(NewPin == NewPinCheck){
                                            writeFunc.open("MoMoPIN.txt");
                                            writeFunc << NewPinCheck;
                                            writeFunc.close();
                                            cout<<"Pin Changed Successfully"<<endl;
                                        }
                                        else{
                                            cout<<"Wrong Pin Please Try Again Later"<<endl;
                                        }

                                    }
                                    j=3;
                                }
                                else if(inp == 2){
                                    j=3;
                                    main();
                                }
                                else{
                                    j++;
                                }
                            }

                            l = 3;
                        }
                        else if(take == 2){
                            cout << "\nAre you sure you want to Reset your MoMo PIN ?"<<endl;
                            cout << "1) Yes"<<endl;
                            cout << "2) No\n"<<endl;
                            int hi;
                            cin >> hi;
                            if(hi == 1){
                                cout<<"\nPlease Enter your MoMo PIN to Confirm Reset\n"<<endl;
                                string inputMoMo, mainMoMo,resetMoMo;
                                cin >> inputMoMo;

                                readFunc.open("MoMoPIN.txt");
                                getline(readFunc,mainMoMo);
                                readFunc.close();

                                readFunc.open("defaultPIN.txt");
                                getline(readFunc,resetMoMo);
                                readFunc.close();

                                if(inputMoMo == mainMoMo){
                                    writeFunc.open("MoMoPIN.txt");
                                    writeFunc << resetMoMo;
                                    writeFunc.close();

                                    cout<<"Your PIN Has successfully Been Reset"<<endl;
                                }
                            }
                            else{
                                cout <<"Invalid Input"<<endl;
                            }

                            l = 3;
                        }
                        else{
                            l ++;;
                        }
                    }
                    h=3;
                }
                else if(inputT==7){
                    cout<<"7"<<endl;
                    h=3;
                }
                else if(inputT==0){
                    h=3;
                    main();
                }
                else{
                    cout<<"Wrong Input, PLEASE TRY AGAIN"<<endl;
                    h++;
                }
            }
            break;
        }
        else {
            counter ++;
            cout<<"Invalid input please try again"<<endl;
        }
    }

    return 0;
}
void Main_Menu(){
    cout << "\nMenu" << endl;
    cout << "1) Transfer Money" << endl;
    cout << "2) MoMoPay & PayBill" << endl;
    cout << "3) Airtime & Bundle" << endl;
    cout << "4) Allow Cash Out" << endl;
    cout << "5) Financial Services" << endl;
    cout << "6) My Wallet\n" << endl;
}
void TranferMoney(){
    cout << "\nTransfer Money" << endl;
    cout << "1) MoMo User" << endl;
    cout << "2) Non MoMo User" << endl;
    cout << "3) Send with Care" << endl;
    cout << "4) Favorite" << endl;
    cout << "5) Other Network" << endl;
    cout << "5) Bank Account" << endl;
    cout << "0) Back\n" << endl;
}
void enterNumber(){
    cout <<"Enter mobile number"<<endl;
}
void confirmNumber(){
    cout <<"Confirm Number"<<endl;
}
void enterAmount(){
    cout <<"Enter Amount"<<endl;
}
void EnterReference(){
    cout <<"Enter Reference"<<endl;
}
void Rec_dets(string RecieverNum, float amount, string reffe){
    cout <<"\nTransfer to - "<<RecieverNum;
    cout <<" an Amount of GHS "<<amount<<endl;
    cout <<"with Reference: " << reffe;
    cout<<" . Fee is GHS 0.00, \nTax amount is GHS 0.00. Total \n" << amount;
    cout<<"\nEnter MoMo PIN To Confirm\n"<<endl;
}
void OtherNetwork(){
    cout << "\nTransfer Money to Other Network" << endl;
    cout << "1) Airtel TIgo" << endl;
    cout << "2) Vodafone" << endl;
    cout << "3) E-zwich" << endl;
    cout << "4) G-Money" << endl;
    cout << "5) Zeepay" << endl;
    cout << "6) GhanaPay" << endl;
    cout << "0) Back\n" << endl;
}

void MoMoPay(){
    cout << "MoMoPay & PayBill" << endl;
    cout << "1) MoMoPay" << endl;
    cout << "2) PayBill" << endl;
    cout << "3) GhQR" << endl;
    cout << "0) Back" << endl;
}
void Airtime(){
    cout << "Airtime & Bundle" << endl;
    cout << "1) Airtimes" << endl;
    cout << "2) Internet Bundles" << endl;
    cout << "3) Fixed Broadband" << endl;
    cout << "4) Schedule Airtime" << endl;
    cout << "5) Just4U" << endl;
    cout << "0) Back" << endl;
}
void Cashout(){
    cout << "Allow Cash Out" << endl;
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cout << "0) Back" << endl;
}
void FinanService(){
    cout << "Financial Services" << endl;
    cout << "1) Bank Services" << endl;
    cout << "2) Savings" << endl;
    cout << "3) Loan" << endl;
    cout << "4) Pension and Investments" << endl;
    cout << "5) Insurance" << endl;
    cout << "6) Trade Shares" << endl;
    cout << "0) Back" << endl;
}
void MyWallet(){
    cout << "\nMy Wallet" << endl;
    cout << "1) Check Balance" << endl;
    cout << "2) Allow Cash Out" << endl;
    cout << "3) My Approvals" << endl;
    cout << "4) Report Fraud" << endl;
    cout << "5) Statement" << endl;
    cout << "6) Change & Reset PIN" << endl;
    cout << "7) Airtime" << endl;
    cout << "0) Back" << endl;
    cout << "# for next\n" << endl;
}
void printBalance(float balance){
    cout<<"\nCurrent Balance: GHS "<<balance<<endl;
    cout<<"Available Balance: GHS "<<balance<<endl;
    cout<<"\n"<<endl;
}
void checkBalance(){
    cout<<"\nFee is GHS 0.00. Enter MM PIN\n"<<endl;
}

void changeReset(){
    cout<<"\nChange & Reset PIN"<<endl;
    cout<<"1)Change PIN"<<endl;
    cout<<"2)Reset PIN\n"<<endl;
}


