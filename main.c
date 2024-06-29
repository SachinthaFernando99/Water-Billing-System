/*
*********************************************************************************************************************************
Title : Water Billing System
Author : AS2020961
Date : 2021.09.29
Version : 1.0
Description : Prints the water bill of a house
*********************************************************************************************************************************
*/

/*-------------------------------------------------------------------------------------------------------------------------------
Begin of samurdhiRecipients function declaration
-------------------------------------------------------------------------------------------------------------------------------*/
void samurdhiRecipients();
/*-------------------------------------------------------------------------------------------------------------------------------
End of samurdhiRecipients function declaration
-------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------
Begin of nonSamurdhiRecipients function declaration
-------------------------------------------------------------------------------------------------------------------------------*/
void nonSamurdhiRecipients();
/*-------------------------------------------------------------------------------------------------------------------------------
End of nonSamurdhiRecipients function declaration
-------------------------------------------------------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-------------------------------------------------------------------------------------------------------------------------------
Begin of main function
-------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
    int intMatrix[4][5]={
    {1001,138,1200,1500,'N'},
    {1002,63,630,500,'S'},
    {1003,255,1450,1450,'N'},
    {1004,79,450,450,'S'},
    };//Declaring the intMatrix array
    int intAccountNumber=0;//Declaring intAccountNumber variable
    int intCount=0;//Declaring intCount variable
    char chrRecipientTypeSamurdhi='S';//Declaring the chrRecipientTypeSamurdhi variable
    int intChrRecipientTypeSamurdhi=(int)chrRecipientTypeSamurdhi;//Declaring the intChrRecipientTypeSamurdhi variable
    char chrRecipientTypeNonSamurdhi='N';//Declaring the chrRecipientTypeNonSamurdhi variable
    int intChrRecipientTypeNonSamurdhi=(int)chrRecipientTypeNonSamurdhi;//Declaring the intChrRecipientTypeNonSamurdhi variable

        printf("Please enter the account number    : ");//Printing a message to the user saying input the account number and scan it
        scanf("%d",&intAccountNumber);

/*-------------------------------------------------------------------------------------------------------------------------------
Begin of Process Part
-------------------------------------------------------------------------------------------------------------------------------*/

        for(intCount=0;intCount<4;intCount++)
        {
            if (intAccountNumber==intMatrix[intCount][0])
            {
                if (intChrRecipientTypeSamurdhi==intMatrix[intCount][4])
                {
                    samurdhiRecipients(intMatrix,intAccountNumber,intCount);//calling the samurdhiRecipients function
                    break;
                }

                else if (intChrRecipientTypeNonSamurdhi==intMatrix[intCount][4])
                {
                    nonSamurdhiRecipients(intMatrix,intAccountNumber,intCount);//calling the nonSamurdhiRecipients function
                    break;
                }
            }
        }

        if (intAccountNumber!=intMatrix[intCount][0])
        {
            printf("\nPlease check the account number again!!!\n");//Printing a message to the user saying the entered account number is wrong
        }

/*-------------------------------------------------------------------------------------------------------------------------------
End of Process Part
-------------------------------------------------------------------------------------------------------------------------------*/

    return 0;
}
/*-------------------------------------------------------------------------------------------------------------------------------
End of main function
-------------------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------------------
Begin of samurdhiRecipients function
-------------------------------------------------------------------------------------------------------------------------------*/
//Precondition : Read the account number, get the count and the array
//Postcondition: Print the water bill
//Description  : Print the water bill and write the bill data in a Data.txt file
void samurdhiRecipients(int intMatrix[4][5],int intAccountNumber,int intCount)
{
    int intUnitsChargeMatrix[10]={5,10,15,40,58,88,105,120,130,140};//Declaring the intUnitsChargeMatrix
    int intServiceChargeMatrix[10]={50,50,50,80,100,200,400,650,1000,1600};//Declaring the intServiceChargeMatrix

    int intUnitUsageCharge=0;//Declaring intUnitUsageCharge variable
    int intMonthlyServiceCharge=0;// Declaring intMonthlyServiceCharge variable
    int intNewMeterReading=0;//Declaring intNewMeterReading variable
    int intMeterCount=0;//Declaring intMeterCount variable
    int intDeficitMoney=0;//Declaring intDeficitMoney variable
    float fltTaxesFee=0;//Declaring fltTaxesFee variable
    int intAdvancedPayment=0;//Declaring intAdvancedPayment variable
    int intWaterCharge=0;//Declaring intWaterCharge variable
    float fltMonthlyPayment=0;//Declaring fltMonthlyPayment variable
    float fltFinalPayment=0;//Declaring fltFinalPayment variable
    float fltCRBalance=0;//Declaring fltCRBalance variable
    int intChargeCount=0;
/*-------------------------------------------------------------------------------------------------------------------------------
Start of process part
-------------------------------------------------------------------------------------------------------------------------------*/
                printf("Please enter the new meter reading : ");//Printing a message to the user saying to enter the new meter reading and scan it
                scanf("%d",&intNewMeterReading);

                intMeterCount=intNewMeterReading-intMatrix[intCount][1];

                    if (intMeterCount<=5)
                    {
                        intUnitUsageCharge=intMeterCount*intUnitsChargeMatrix[intChargeCount];
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=10)
                    {
                        intChargeCount=intChargeCount+1;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-5)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=15)
                    {
                        intChargeCount=intChargeCount+2;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-10)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=20)
                    {
                        intChargeCount=intChargeCount+3;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-15)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=25)
                    {
                        intChargeCount=intChargeCount+4;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-4]*5)+(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-20)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=30)
                    {
                        intChargeCount=intChargeCount+5;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-5]*5)+(intUnitsChargeMatrix[intChargeCount-4]*5)+(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-25)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=40)
                    {
                        intChargeCount=intChargeCount+6;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-6]*5)+(intUnitsChargeMatrix[intChargeCount-5]*5)+(intUnitsChargeMatrix[intChargeCount-4]*5)+(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-30)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=50)
                    {
                        intChargeCount=intChargeCount+7;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-7]*5)+(intUnitsChargeMatrix[intChargeCount-6]*5)+(intUnitsChargeMatrix[intChargeCount-5]*5)+(intUnitsChargeMatrix[intChargeCount-4]*5)+(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-40)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=75)
                    {
                        intChargeCount=intChargeCount+8;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-8]*5)+(intUnitsChargeMatrix[intChargeCount-7]*5)+(intUnitsChargeMatrix[intChargeCount-6]*5)+(intUnitsChargeMatrix[intChargeCount-5]*5)+(intUnitsChargeMatrix[intChargeCount-4]*5)+(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-50)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }
                    else
                    {
                        intChargeCount=intChargeCount+9;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-9]*5)+(intUnitsChargeMatrix[intChargeCount-8]*5)+(intUnitsChargeMatrix[intChargeCount-7]*5)+(intUnitsChargeMatrix[intChargeCount-6]*5)+(intUnitsChargeMatrix[intChargeCount-5]*5)+(intUnitsChargeMatrix[intChargeCount-4]*5)+(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-75)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }


                intWaterCharge=intUnitUsageCharge+intMonthlyServiceCharge;
                fltTaxesFee=(intWaterCharge)*(3)/(100.0);
                fltMonthlyPayment=intWaterCharge+fltTaxesFee;
                intDeficitMoney=intMatrix[intCount][2]-intMatrix[intCount][3];
                fltFinalPayment=fltMonthlyPayment+intDeficitMoney;

/*-------------------------------------------------------------------------------------------------------------------------------
End of process part
-------------------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------------------
Beginning of Printing the output
-------------------------------------------------------------------------------------------------------------------------------*/

                printf("\n\n******************************************************\n");
                printf("\n                      WATER BILL                      \n");
                printf("\n******************************************************\n");
                printf("\nThis is a Samurdhi house\n");
                printf("Your previous bill amount is   : Rs %d\n",intMatrix[intCount][2]);
                printf("Your previous bill payment is  : Rs %d\n",intMatrix[intCount][3]);
                printf("\n******************************************************\n");
                printf("\nThe new meter reading is       : %d\n",intNewMeterReading);
                printf("The previous meter reading is  : %d\n",intMatrix[intCount][1]);
                printf("This month your consumption is : %d\n",intMeterCount);
                printf("\n******************************************************\n");
                printf("\nWater charge for this month is : Rs %d\n",intWaterCharge);
                printf("Charges for this month is      : Rs %.2f\n",fltMonthlyPayment);
                if (intDeficitMoney>=0)
                {
                    printf("Your deficit money balance is  : Rs %d\n",intDeficitMoney);
                    printf("\n******************************************************\n");
                }
                else
                {
                    intAdvancedPayment=(-1)*(intDeficitMoney);
                    printf("Previous month CR balance is   : Rs %d\n",intAdvancedPayment);
                    printf("\n******************************************************\n");
                }
                if (fltFinalPayment>0)
                {
                    printf("\nTotal amount due is            : Rs %.2f\n",fltFinalPayment);
                    printf("\n******************************************************\n");

/*-------------------------------------------------------------------------------------------------------------------------------
Beginning of writing the final outputs in the Data.txt file
-------------------------------------------------------------------------------------------------------------------------------*/

                    FILE *fileWritePtr;
                    fileWritePtr=fopen("Data.txt","a");
                    fprintf(fileWritePtr,"Recipient type    : Samurdhi\nAccount Number    : %d\nNew meter reading : %d\nTotal amount due  : Rs %.2f\n\n",intAccountNumber,intNewMeterReading,fltFinalPayment);
                    fclose(fileWritePtr);

/*-------------------------------------------------------------------------------------------------------------------------------
End of writing the final outputs in the Data.txt file
-------------------------------------------------------------------------------------------------------------------------------*/

                }
                else
                {
                    fltCRBalance=(-1)*fltFinalPayment;
                    printf("\nYour this month CR balance is  : Rs %.2f\n",fltCRBalance);
                    printf("\n******************************************************\n");

/*-------------------------------------------------------------------------------------------------------------------------------
Beginning of writing the final outputs in the Data.txt file
-------------------------------------------------------------------------------------------------------------------------------*/

                    FILE* fileWritePtr;
                    fileWritePtr=fopen("Data.txt","a");
                    fprintf(fileWritePtr,"Recipient type    : Samurdhi\nAccount Number    : %d\nNew meter reading : %d\nCR Balance        : Rs %.2f\n\n",intAccountNumber,intNewMeterReading,fltCRBalance);
                    fclose(fileWritePtr);

/*-------------------------------------------------------------------------------------------------------------------------------
End of writing the final outputs in the Data.txt file
-------------------------------------------------------------------------------------------------------------------------------*/
                }

/*-------------------------------------------------------------------------------------------------------------------------------
End of Printing the output part
-------------------------------------------------------------------------------------------------------------------------------*/

}

/*-------------------------------------------------------------------------------------------------------------------------------
End of samurdhiRecipients function
-------------------------------------------------------------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------------------------------------------------------------
Beginning of nonSamurdhiRecipients function
-------------------------------------------------------------------------------------------------------------------------------*/
//Precondition : Read the account number, get the intcount and the array
//Postcondition: Print the water bill
//Description  : Print the water bill and write the bill data in a Data.txt file
void nonSamurdhiRecipients(int intMatrix[4][5],int intAccountNumber,int intCount)
{
    int intUnitsChargeMatrix[10]={8,11,20,40,58,88,105,120,130,140};//Declaring the intUnitsChargeMatrix
    int intServiceChargeMatrix[10]={50,65,70,80,100,200,400,650,1000,1600};//Declaring the intServiceChargeMatrix

    int intUnitUsageCharge=0;//Declaring intUnitUsageCharge variable
    int intMonthlyServiceCharge=0;// Declaring intMonthlyServiceCharge variable
    int intNewMeterReading=0;//Declaring intNewMeterReading variable
    int intMeterCount=0;//Declaring intMeterCount variable
    int intDeficitMoney=0;//Declaring intDeficitMoney variable
    float fltTaxesFee=0;//Declaring fltTaxesFee variable
    int intAdvancedPayment=0;//Declaring intAdvancedPayment variable
    int intWaterCharge=0;//Declaring intWaterCharge variable
    float fltMonthlyPayment=0;//Declaring fltMonthlyPayment variable
    float fltFinalPayment=0;//Declaring fltFinalPayment variable
    float fltCRBalance=0;//Declaring fltCRBalance variable
    int intChargeCount=0;//Declaring intChargeCount variable

/*-------------------------------------------------------------------------------------------------------------------------------
Start of process part
-------------------------------------------------------------------------------------------------------------------------------*/

                printf("Please enter the new meter reading : ");//Printing a message to the user saying to enter the new meter reading and scan it
                scanf("%d",&intNewMeterReading);

                intMeterCount=intNewMeterReading-intMatrix[intCount][1];

                    if (intMeterCount<=5)
                    {
                        intUnitUsageCharge=intMeterCount*intUnitsChargeMatrix[intChargeCount];
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=10)
                    {
                        intChargeCount=intChargeCount+1;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-5)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=15)
                    {
                        intChargeCount=intChargeCount+2;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-10)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=20)
                    {
                        intChargeCount=intChargeCount+3;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-15)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=25)
                    {
                        intChargeCount=intChargeCount+4;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-4]*5)+(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-20)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=30)
                    {
                        intChargeCount=intChargeCount+5;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-5]*5)+(intUnitsChargeMatrix[intChargeCount-4]*5)+(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-25)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=40)
                    {
                        intChargeCount=intChargeCount+6;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-6]*5)+(intUnitsChargeMatrix[intChargeCount-5]*5)+(intUnitsChargeMatrix[intChargeCount-4]*5)+(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-30)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=50)
                    {
                        intChargeCount=intChargeCount+7;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-7]*5)+(intUnitsChargeMatrix[intChargeCount-6]*5)+(intUnitsChargeMatrix[intChargeCount-5]*5)+(intUnitsChargeMatrix[intChargeCount-4]*5)+(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-40)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                    else if (intMeterCount<=75)
                    {
                        intChargeCount=intChargeCount+8;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-8]*5)+(intUnitsChargeMatrix[intChargeCount-7]*5)+(intUnitsChargeMatrix[intChargeCount-6]*5)+(intUnitsChargeMatrix[intChargeCount-5]*5)+(intUnitsChargeMatrix[intChargeCount-4]*5)+(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-50)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }
                    else
                    {
                        intChargeCount=intChargeCount+9;
                        intUnitUsageCharge=(intUnitsChargeMatrix[intChargeCount-9]*5)+(intUnitsChargeMatrix[intChargeCount-8]*5)+(intUnitsChargeMatrix[intChargeCount-7]*5)+(intUnitsChargeMatrix[intChargeCount-6]*5)+(intUnitsChargeMatrix[intChargeCount-5]*5)+(intUnitsChargeMatrix[intChargeCount-4]*5)+(intUnitsChargeMatrix[intChargeCount-3]*5)+(intUnitsChargeMatrix[intChargeCount-2]*5)+(intUnitsChargeMatrix[intChargeCount-1]*5)+((intMeterCount-75)*intUnitsChargeMatrix[intChargeCount]);
                        intMonthlyServiceCharge=intServiceChargeMatrix[intChargeCount];
                    }

                intWaterCharge=intUnitUsageCharge+intMonthlyServiceCharge;
                fltTaxesFee=(intWaterCharge)*(5)/(100.0);
                fltMonthlyPayment=intWaterCharge+fltTaxesFee;
                intDeficitMoney=intMatrix[intCount][2]-intMatrix[intCount][3];
                fltFinalPayment=fltMonthlyPayment+intDeficitMoney;

/*-------------------------------------------------------------------------------------------------------------------------------
End of process part
-------------------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------------------
Beginning of Printing the output
-------------------------------------------------------------------------------------------------------------------------------*/

                printf("\n\n******************************************************\n");
                printf("\n                      WATER BILL                      \n");
                printf("\n******************************************************\n");
                printf("\nThis is a NonSamurdhi house\n");
                printf("Your previous bill amount is   : Rs %d\n",intMatrix[intCount][2]);
                printf("Your previous bill payment is  : Rs %d\n",intMatrix[intCount][3]);
                printf("\n******************************************************\n");
                printf("\nThe new meter reading is       : %d\n",intNewMeterReading);
                printf("The previous meter reading is  : %d\n",intMatrix[intCount][1]);
                printf("This month your consumption is : %d\n",intMeterCount);
                printf("\n******************************************************\n");
                printf("\nWater charge for this month is : Rs %d\n",intWaterCharge);
                printf("Charges for this month is      : Rs %.2f\n",fltMonthlyPayment);
                if (intDeficitMoney>=0)
                {
                    printf("Your deficit money balance is  : Rs %d\n",intDeficitMoney);
                    printf("\n******************************************************\n");
                }
                else
                {
                    intAdvancedPayment=(-1)*(intDeficitMoney);
                    printf("Previous month CR balance is   : Rs %d\n",intAdvancedPayment);
                    printf("\n******************************************************\n");
                }
                if (fltFinalPayment>0)
                {
                    printf("\nTotal amount due is            : Rs %.2f\n",fltFinalPayment);
                    printf("\n******************************************************\n");

/*-------------------------------------------------------------------------------------------------------------------------------
Beginning of writing the final outputs in the Data.txt file
-------------------------------------------------------------------------------------------------------------------------------*/

                    FILE *fileWritePtr;
                    fileWritePtr=fopen("Data.txt","a");
                    fprintf(fileWritePtr,"Recipient type    : NonSamurdhi\nAccount Number    : %d\nNew meter reading : %d\nTotal amount due  : Rs %.2f\n\n",intAccountNumber,intNewMeterReading,fltFinalPayment);
                    fclose(fileWritePtr);

/*-------------------------------------------------------------------------------------------------------------------------------
End of writing the final outputs in the Data.txt file
-------------------------------------------------------------------------------------------------------------------------------*/

                }
                else
                {
                    fltCRBalance=(-1)*fltFinalPayment;
                    printf("\nYour this month CR balance is  : Rs %.2f\n",fltCRBalance);
                    printf("\n******************************************************\n");

/*-------------------------------------------------------------------------------------------------------------------------------
Beginning of writing the final outputs in the Data.txt file
-------------------------------------------------------------------------------------------------------------------------------*/

                    FILE *fileWritePtr;
                    fileWritePtr=fopen("Data.txt","a");
                    fprintf(fileWritePtr,"Recipient type    : NonSamurdhi\nAccount Number    : %d\nNew meter reading : %d\nCR Balance        : Rs %.2f\n\n",intAccountNumber,intNewMeterReading,fltCRBalance);
                    fclose(fileWritePtr);

/*-------------------------------------------------------------------------------------------------------------------------------
End of writing the final outputs in the Data.txt file
-------------------------------------------------------------------------------------------------------------------------------*/

                }

/*-------------------------------------------------------------------------------------------------------------------------------
End of Printing the output part
-------------------------------------------------------------------------------------------------------------------------------*/

}
/*-------------------------------------------------------------------------------------------------------------------------------
End of nonSamurdhiRecipients function
-------------------------------------------------------------------------------------------------------------------------------*/



