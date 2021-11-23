#include "unity.h"
#include "parking_system.h"

#include "parking_system.h"
#define PROJECT_NAME    "Parking System"

/* prototypes for test functions */

void display( ) ;
void changecol ( struct vehicle * ) ;
struct vehicle * add ( int, int, int, int ) ;
void del ( struct vehicle * ) ;
void getfreerowcol ( int, int * ) ;
void getrcbyinfo ( int, int, int * ) ;
void show() ;
int randint();
int backupw();
int backupr();
struct vehicle * addonstart ( int, int, int, int ) ;
void total_bill(int ,struct tm *ct1,struct tm *ct2);
void get_arrival_time(int);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main( )
{
	int choice, type, number, row = 0, col = 0 ;
	int i, tarr[2] ;
	int finish = 1 ;
	backupr();



  system ( "cls" ) ;

	/* displays menu and calls corresponding functions */
	while ( finish )
	{
    system ( "cls" ) ;

		printf ( "\nCar Parking\n" ) ;
		printf ( "1. Arrival of a vehicle\n" ) ;
		printf ( "2. Total no. of vehicles parked\n" ) ;
		printf ( "3. Total no. of cars parked\n" ) ;
		printf ( "4. Total no. of scooters parked\n" ) ;
		printf ( "5. Display order in which vehicles are parked\n" ) ;
		printf ( "6. Departure of vehicle\n" ) ;
		printf ( "7. Chek History\n" ) ;
		printf ( "8. Exit\n" ) ;

		scanf ( "%d", &choice ) ;

		switch ( choice )
		{
			case 1 :
          system ( "cls" ) ;
				  printf ( "\nAdd: \n" ) ;

          type = 0 ;

          /* check for vehicle type */
          while ( type != CAR && type != SCOOTER )
          {
					  printf ( "Enter vehicle type (1 for Car / 2 for Scooter ): \n" ) ;
            scanf ( "%d", &type ) ;
	          if ( type != CAR && type != SCOOTER )
						  printf ( "\nInvalid vehicle type.\n" ) ;
          }

				  printf ( "Enter vehicle number: " ) ;
				  scanf ( "%d", &number ) ;

				  /* add cars' data */
				  if ( type == CAR || type == SCOOTER )
				  {
					  getfreerowcol ( type, tarr ) ;

					  if ( tarr[0] != -1 && tarr[1] != -1 )
					  {
						  row = tarr[0] ;
						  col = tarr[1] ;

              if ( type == CAR )
                car[row][col] =  add ( type, number, row, col ) ;
              else
							  scooter[row - 2][col] = add ( type, number, row, col ) ; ;
            }
					  else
            {
              if ( type == CAR )
                printf ( "\nNo parking slot free to park a car\n" ) ;
              else
                printf ( "\nNo parking slot free to park a scooter\n" ) ;
            }
          }
				  else
				  {
            printf ( "Invalid type\n" ) ;
					  break ;
          }

          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

      case 2 :
          system ( "cls" ) ;
				  printf ( "Total vehicles parked: %d\n", vehcount ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 3 :
          system ( "cls" ) ;
				  printf ( "Total cars parked: %d\n", carcount ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 4 :
          system ( "cls" ) ;
				  printf ( "Total scooters parked: %d\n", scootercount ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 5 :
          system ( "cls" ) ;
				  printf ( "Display\n" ) ;
				  display( ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 6 :      //problem area ................................................
          system ( "cls" ) ;
				  printf ( "Departure\n" ) ;
          type = 0 ;
          /* check for vehicle type */
          while ( type != CAR && type != SCOOTER )
          {
					  printf ( "Enter vehicle type (1 for Car / 2 for Scooter ): \n" ) ;
            scanf ( "%d", &type ) ;
	          if ( type != CAR && type != SCOOTER )
						  printf ( "\nInvalid vehicle type.\n" ) ;
          }
				  printf ( "Enter number: "  ) ;
				  scanf ( "%d", &number ) ;

  				if ( type == CAR || type == SCOOTER )
	  			{


		  			getrcbyinfo ( type, number, tarr ) ;
			  		if ( tarr[0] != -1 && tarr[1] != -1 )
				  	{
				  	    insertrecord2(number,datetime());
				  	    get_arrival_time(number);
              col = tarr [1] ;
              /* if the vehicle is car */
              if ( type == CAR )
              {
                row = tarr [0] ;
	              del ( car [row][col] ) ;

				                    for ( i = col ; i < 9 ; i++ )
							  {
								  car[row][i] = car[row][i + 1] ;
								 // changecol ( car[row][col] ) ;
							  }
                free ( car[row][i] ) ;

					  car[row][i] = NULL ;
              }
						  /* if a vehicle is scooter */
						  else
              {
                row = tarr[0] - 2 ;
							  if ( ! ( row < 0 ) )
							  {
								  del ( scooter[row][col] ) ;
								  for ( i = col ; i < 9 ; i++ )
								  {
									  scooter[row][i] = scooter[row][i + 1] ;
									  //changecol ( scooter[row][col] ) ;
								  }
								  scooter[row][i] = NULL ;
                }
              }
            }
					  else
            {
              if ( type == CAR )
							  printf ( "\nInvalid car number, or a car with such number has not been parked here.\n" ) ;
              else
                printf ( "\nInvalid scooter number, or a scooter with such number has not been parked here.\n" ) ;
            }
          }
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 8 :

          system ( "cls" ) ;
          for ( row = 0 ; row < 2 ; row++ )
          {
            for ( col = 0 ; col < 10 ; col++ )
            {
              if ( car[row][col] -> num != 0 )
                free ( car[row][col] ) ;
              if ( scooter[row][col] -> num != 0 )
							  free ( scooter[row+2][col] ) ;
            }
          }
				  finish = 0 ;




				   getch();
				  break ;

            case 7 :
              system ( "cls" ) ;
     int opt ;
		printf ( "RECORD TABLES\n" ) ;
  			 printf ( "Press 1 for Arrival history\n" ) ;
                         printf ( "Press 2 for Departure history\n" ) ;
                                printf ( "Press 3 for Fine Sheet\n" ) ;
     			scanf ( "%d", &opt ) ;
           historyrec(opt);
 printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
                break ;
    }
	}
  return 0 ;
}