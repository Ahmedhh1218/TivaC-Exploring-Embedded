#include"DIO.h"
#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"

#define SIZE          10
#define SW_MASK       (0x11)  
#define VALUE         (DIO_ReadPort(PORTF) & SW_MASK)
int main()
{
  uint8 arr[SIZE] = {1,2,3,4,5,6,7,8,9,10};
  int8 flag = 0 , temp , i =0;
  DIO_Init_port(PORTF,0X0E);
  DIO_WritePort(PORTF,0x0);
  for(;;) 
  {
    if (i >9)
    {
      i =0;
    }
    temp = arr[i];
    if ( (temp % 2 == 0) && ((VALUE == 0x10) || (VALUE == 0x01) || (VALUE == 0x00) ) )
    {
      for (uint32 i = 0; i<1000000; i++);
      if ( (temp % 2 == 0) && ((VALUE == 0x10) || (VALUE == 0x01)) || (VALUE == 0x00) )
      {
        if(flag == 0)
        {
          DIO_WritePort(PORTF,0x04);
          i++;
          //set the button flag value to 1 to not enter here again until the button is released.
          flag = 1;
        }
        
      }
      
    }
    else
    {
      for (uint32 i = 0; i<1000000; i++);
      DIO_WritePort(PORTF,0x0);
      flag = 0;
    }
    
    if ( (temp % 2 != 0) && ((VALUE == 0x10) || (VALUE == 0x01)) || (VALUE == 0x00) )
    {
      for (uint32 i = 0; i<1000000; i++);
      if ( (temp % 2 != 0) && ((VALUE == 0x10) || (VALUE == 0x01)) || (VALUE == 0x00) )
      {
        
        if(flag == 0)
        {
          DIO_WritePort(PORTF,0x02);
          i++;
          //set the button flag value to 1 to not enter here again until the button is released.
          flag = 1;
        }
      }
      
    }
    else
    {
      for (uint32 i = 0; i<1000000; i++);
      DIO_WritePort(PORTF,0x0);
      flag=0;
    }
    
  }
  return 0;
}              
