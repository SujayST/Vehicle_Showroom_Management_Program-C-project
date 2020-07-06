#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

class customer   // Customer Class: for each customer one class will be create and add to database
{
    public:
            string Name;
            string Contact_no;

    customer(string name,string n):Contact_no(n){
    Name=name;
    }
    customer(){}
  /*  customer(){
        cout<<"\nEnter the Customer Name : ";
        cin>>Name;
        cout<<"Enter Customer Contact no. : ";
        cin>>Contact_no;
       }*/

    void PrintDetails()
    {
        cout<<"\nCustomer Name : "<<Name;
        cout<<"\nCustomer Contact_no : "<<Contact_no;
    }
};

class SUV                 //parent class for SUV segment
{
    public:
            int Tax_percentage;
            string price_Range;

    SUV():Tax_percentage(18),price_Range("Rs.8-12 lacs") {}
    virtual int Price(){
            }
    virtual void DisplaySpecs(){}
    virtual void DisplayOwnerDetails(){}
};

class SEDAN
{
   public:
            int Tax_percentage;
            string price_Range;

    SEDAN():Tax_percentage(18),price_Range("Rs.8-12 lacs") {}
    virtual int Price(){}
    virtual void DisplaySpecs(){}
    virtual void DisplayOwnerDetails(){}
};

class HatchBack
{
     public:
            int Tax_percentage;
            string price_Range;

    HatchBack():Tax_percentage(18),price_Range("Rs.8-12 lacs") {}
    virtual int Price(){}
    virtual void DisplaySpecs(){}
    virtual void DisplayOwnerDetails(){}
};



class ShowRoom
{
    public:
            string CompanyName;
            string ShowroomLocation;
    private:
            int NoOfCarsSold;
            int NoOfCarsAvailable;
            int TotalTurnOver;
            int TotalGstToBePaid;

    public:
            vector <SUV*> SUVCount;
            vector <SEDAN*> SedanCount;
            vector <HatchBack*> HBCount;
            int scross,ciaz,baleno, ignis;
            int suvsold,sedansold,hatchbacksold;

    ShowRoom():NoOfCarsSold(0),TotalTurnOver(0),TotalGstToBePaid(0),suvsold(0),sedansold(0),hatchbacksold(0)
    {
        cout<<"Enter the Company Name of the Showroom : ";
        cin>>CompanyName;
        cin.clear();
        cin.ignore();
        cout<<"\nEnter the Showroom location : ";
        cin>>ShowroomLocation;
        cin.clear();
        cin.ignore();
        cout<<"\nEnter the Cars availability data :\n";
        cout<<"SUVs :\n \t No of SCROSS available :   ";
        cin>>scross;
        cin.clear();
        cin.ignore();
        cout<<"Sedans :\n \t No of Ciaz available :   ";
        cin>>ciaz;
        cin.clear();
        cin.ignore();
        cout<<"Hatchbacks :\n \t No of Baleno available :   ";
        cin>>baleno;
        cin.clear();
        cin.ignore();
        cout<<"\n\t No of Ignis available :   ";
        cin>>ignis;
        cin.clear();
        cin.ignore();
        NoOfCarsAvailable=scross+ciaz+baleno+ignis;
    }

    void print_Sales_details()
    {
       cout<<"\nSales Details of the Current Fiscal Year: \n";
       cout<<"_________________________________________";
       cout<<"\nTotal NO. of Cars Sold: ";
       cout<<"\n  SUVs sold : "<<suvsold<<"\n  Sedans sold : "<<sedansold<<"\n  Hatchbacks sold : "<<hatchbacksold;
       cout<<"\n\nTotal Revenue Generated : Rs."<<TotalTurnOver-TotalGstToBePaid;
       cout<<"\nTotal GST to be Paid : Rs."<<TotalGstToBePaid;
       cout<<"\nTurn TurnOver : Rs."<<TotalTurnOver;

    }
    void print_cars_count()
    {
       cout<<"\nCars Count :\n";
       cout<<"\nTotal NO. of Cars Sold: ";
       cout<<"\n  SUVs sold : "<<suvsold<<"\n  Sedans sold : "<<sedansold<<"\n  Hatchbacks sold : "<<hatchbacksold;
       cout<<"\nTotal NO. of Cars Available: ";
       cout<<"\n  Scross available : "<<scross<<"\n  Ciaz available : "<<ciaz<<"\n  Baleno available : "<<baleno<<"\n  ignis available : "<<ignis;

    }
    void AnnualReset()
    {
        NoOfCarsSold=TotalTurnOver=TotalGstToBePaid=suvsold=sedansold=hatchbacksold=0;
        cout<<"\nAnnual Reset Complete!";
    }
    void SellSUV(SUV* car)
    {
        if(scross<1)
            throw "SUVs all SOLD out!";

        suvsold++;
        NoOfCarsSold++;
        NoOfCarsAvailable--;
        scross--;
        SUVCount.push_back(car);
        TotalTurnOver+=car->Price();
        TotalGstToBePaid+=(car->Price()*car->Tax_percentage)/100;

    }

    void SellSedan(SEDAN* car)
    {
        if(ciaz<1)
            throw "Sedans all SOLD out!";

        sedansold++;
        NoOfCarsSold++;
        NoOfCarsAvailable--;
        ciaz--;
        SedanCount.push_back(car);
        TotalTurnOver+=car->Price();
        TotalGstToBePaid+=(car->Price()*car->Tax_percentage)/100;

    }
    void SellHatchBack(HatchBack* car)
    {


        if(baleno<1)
            throw "Balenos all SOLD out!";

        hatchbacksold++;
        NoOfCarsSold++;
        NoOfCarsAvailable--;
        baleno--;
        HBCount.push_back(car);
        TotalTurnOver+=car->Price();
        TotalGstToBePaid+=(car->Price()*car->Tax_percentage)/100;

    }

};


class Manager:public ShowRoom
{
    public:
            string ManagerName;
            string EmpID;
            string Password;
    Manager():ShowRoom(){
        cout<<"\nEnter the Manager Name : ";
        scanf("%s",ManagerName);
        cout<<"\nEnter Manager Employ ID : ";
        cin>>EmpID;
        cout<<"\nEnter New Password for Showroom data Access : ";
        cin>>Password;
    }

    void PrintSalesInfo()
    {
    ShowRoom::print_Sales_details();
    }
    void printCarsCount()
    {
    ShowRoom::print_cars_count();
    }
    void reset()
    {
    ShowRoom::AnnualReset();
    }
    void MSUV(SUV* car)
    {
    ShowRoom::SellSUV(car);
    }
    void MSedan(SEDAN* car)
    {
    ShowRoom::SellSedan(car);
    }
    void MHatchBAck(HatchBack* car)
    {
    ShowRoom::SellHatchBack(car);
    }

};

class SCROSS:public SUV
{
    public:
            string ModelName;
            customer purchasedBy;
            string PurchaseDate;
            int BasePrice;
    SCROSS( customer cust, string date):purchasedBy(cust),PurchaseDate(date)
    {
    ModelName="SCROSS";
    BasePrice=800000;
    }
    int Price(){
    return BasePrice+((BasePrice*Tax_percentage)/100);
    }
    void DisplaySpecs()
    {
    cout<<"\n\tModel Name : "<<ModelName;
    cout<<"\n\tMileage : 19 Kmph";
    cout<<"\n\tCapacity : 7 seater";
    cout<<"\n\tEngine : 1.2l VVT";
    cout<<"\n\tPower : 1400cc";
    cout<<"\n\tEx Showroom Price : "<<BasePrice;
    }
    void DisplayOwnerDetails(){

    purchasedBy.PrintDetails();

    }

};


class CIAZ:public SEDAN
{
   public:
            string ModelName;
            customer purchasedBy;
            string PurchaseDate;
            int BasePrice;
    CIAZ( customer cust ,string date):PurchaseDate(date)
    {
    ModelName="CIAZ";
    purchasedBy=cust;
    BasePrice=1000000;
    }
    int Price()
    {
    return BasePrice+((BasePrice*Tax_percentage)/100);
    }
    void DisplaySpecs()
    {
    cout<<"\n\tModel Name : "<<ModelName;
    cout<<"\n\tMileage : 22 Kmph";
    cout<<"\n\tCapacity : 5 seater";
    cout<<"\n\tEngine : 1.5l VVT";
    cout<<"\n\tPower : 1600cc";
    cout<<"\n\tEx Showroom Price : "<<BasePrice;
    }
    void DisplayOwnerDetails(){
    purchasedBy.PrintDetails();
    }
};

class IGNIS:public HatchBack
{
   public:
            string ModelName;
            customer purchasedBy;
            string PurchaseDate;
            int BasePrice;
    IGNIS( customer Cust, string date):purchasedBy(Cust),PurchaseDate(date)
    {
    ModelName="IGNIS";
    BasePrice=500000;
    }
    int Price()
    {
    return BasePrice+((BasePrice*Tax_percentage)/100);
    }
    void DisplaySpecs()
    {
    cout<<"\n\tModel Name : "<<ModelName;
    cout<<"\n\tMileage : 19 Kmph";
    cout<<"\n\tCapacity : 5 seater";
    cout<<"\n\tEngine : 1.0l VVT";
    cout<<"\n\tPower : 1000cc";
    cout<<"\n\tEx Showroom Price : "<<BasePrice;
    }
    void DisplayOwnerDetails()
    {
    purchasedBy.PrintDetails();
    }
};
class BALENO:public HatchBack
{
   public:
            string ModelName;
            customer purchasedBy;
            string PurchaseDate;
            int BasePrice;
    BALENO( customer cust, string date):purchasedBy(cust),PurchaseDate(date){
    ModelName="BALENO";
    BasePrice=700000;
    }
    int Price()
    {
    return BasePrice+((BasePrice*Tax_percentage)/100);
    }
    void DisplaySpecs()
    {
    cout<<"\n\tModel Name : "<<ModelName;
    cout<<"\n\tMileage : 19 Kmph";
    cout<<"\n\tCapacity : 5 seater";
    cout<<"\n\tEngine : 1.2l VVT";
    cout<<"\n\tPower : 1250cc";
    cout<<"\n\tEx Showroom Price : "<<BasePrice;
    }
    void DisplayOwnerDetails(){
    purchasedBy.PrintDetails();
    }
};
// Main function of the program
int main()
{
    printf("\nWELCOME TO SHOWROOM MANAGEMENT PORTAL!\n\n");
    time_t now = time(0);
    char* dt = ctime(&now);
    customer D(dt,dt);
    SCROSS scross(D,dt);        //Demo CARs
    CIAZ ciaz(D,dt);
    BALENO baleno(D,dt);
    IGNIS ignis(D,dt);
    Manager M1;                //Create Manager Object which in turn Creates Showroom Object
   // printf("%s",M1.ManagerName);

    int n, n1,n2,n3,h=1;
    while(h)
    {
        printf("\n\nPlease Select the relevant option: \n");
        printf("_____________________________________\n");
        printf("1)Enter the Customers Portal\n2)Enter Manager's Portal\n->");
        scanf("%d",&n1);
        if(n1==2)                                             // Managers Portal
            {
            string pasd;
            printf("\nWELCOME TO MANAGER'S PORTAL!\n\nPlease enter the Showroom DATA ACCESS Password:\n ->");
            cin>>pasd;
            try
            {
                if(pasd!=M1.Password)
                    throw "INNCORRECT PASSWORD!\n\n ACCESS DENIED!\n";
            }
            catch(const char* msg){
            printf("%s",msg);
             goto cat2;
            }

            printf("\nManager of this showroom: %s.",M1.ManagerName);
            cat1:
            printf("\n_______________________________________");
            printf("\nPlease select the Task you wanna preform: ");
            printf("\n___________________________________________________");
            printf("\n1)Print Sales Details\n2)Print Cars Count\n3)Reset the Showroom Data\n4)Exit Manager's portal\n->");
            scanf("%d",&n2);
            switch(n2)
            {
                case 1:
                    M1.PrintSalesInfo();
                    break;
                case 2:
                    M1.printCarsCount();
                    break;
                case 3:
                    M1.AnnualReset();
                    break;
                case 4:
                    goto cat2;
                    break;
                default:
                    printf("\nPlease Enter a relevant option");


            }
            goto cat1;
            cat2:
            printf("Exiting Manager's Portal.....");
        }
        else if(n1==1)                                // Customers Portal
        {
            printf("\nWELCOME TO CUSTOMERS PORTAL!");
            printf("\nI'm Mr.%s , manager of this showroom.\n\n",M1.ManagerName);
            cout<<"\nEnter the Customer Name : ";
            string Name,Contact_no;
            cin>>Name;
            cout<<"Enter Customer Contact no. : ";
            cin>>Contact_no;
            customer C(Name,Contact_no);
            printf("\n___________________________________________________");

            catlogue:                                         // Flag for looping catalogue function
            printf("\nPlease select the Car Segment you want to Explore: ");
            printf("\n___________________________________________________");
            printf("\n1)All Segments\n2)SUV\n3)Sedan\n4)HatchBack\n->");
            scanf("%d",&n2);
            switch(n2)
            {
                case 1:
                    printf("\n1)SUVs:\n");
                    printf("   #SCROSS");
                    scross.DisplaySpecs();
                    printf("\n2)Sedans:\n");
                    printf("   #CIAZ");
                    ciaz.DisplaySpecs();
                    printf("\n3)HatchBacks:\n");
                    printf("   #BALENO");
                    baleno.DisplaySpecs();
                    printf("\n   #IGNIS");
                    baleno.DisplaySpecs();
                    break;
                case 2:
                    printf("\n1)SUVs:\n");
                    printf("   #SCROSS");
                    scross.DisplaySpecs();
                    break;
                case 3:
                    printf("   2)Sedans:\n");
                    printf("   #CIAZ");
                    ciaz.DisplaySpecs();
                    break;
                case 4:
                    printf("\n3)HatchBacks:\n");
                    printf("   #BALENO");
                    baleno.DisplaySpecs();
                    printf("\n   #IGNIS");
                    baleno.DisplaySpecs();
                    break;
                default:
                    printf("\nPlease Enter a relevant option");
                    goto catlogue;
            }
             printf("\nPlease select the Car you want to Purchase: ");
            printf("\n___________________________________________________");
            printf("\n1)SCROSS\n2)CIAZ\n3)BALENO\n4)IGNIS\n5)Go to previous Menu\n->");
            scanf("%d",&n3);
            try
            {
            if(n3==1)
            {
                SCROSS C1(C,dt);
                M1.SellSUV(&C1);
            }
            else if(n3==2)
            {
                CIAZ C2(C,dt);
                M1.SellSedan(&C2);
             }
             else if(n3==3)
             {
                BALENO C3(C,dt);
                M1.SellHatchBack(&C3);
             }
             else if(n3==4)
             {
                IGNIS C4(C,dt);
                M1.SellHatchBack(&C4);
             }
             else if(n3==5)
                goto catlogue;
             else{
                    printf("\nPlease Enter a relevant option");
                goto catlogue;
             }

            printf("\nCONGRATULATIONS!!!\nThank You for purchasing the vehicle!\n");
            printf("Exiting Customers Portal.....");
            }
            catch(const char* msg){
            printf("%s",msg);
            }
        }

        else
            printf("\nPlease Enter a relevant option");

    }
}

