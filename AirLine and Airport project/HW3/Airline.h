#ifndef __COMP__
#define __COMP__

#include "Flight.h"
#include "AirportManager.h"
#include "GeneralList.h"
typedef unsigned char BYTE;

typedef enum { eNone, eSourceName, eDestName,eDate, ePlaneCode,eNofSortOpt } eSortOption;
static const char* sortOptStr[eNofSortOpt];


typedef struct
{
	char*		name;
	int			flightCount;
	Flight**	flightArr;
	eSortOption	sortOpt;
	LIST		flighDateList;
}Airline;

int		initAirlineFromFile(Airline* pComp, AirportManager* pManaer, const char* fileName, int compressIndictor);
void	initAirline(Airline* pComp);
int		addFlight(Airline* pComp,const AirportManager* pManager);
void	printCompany(const Airline* pComp);
//void	printFlightArr(Flight** pFlight, int size);
void	doCountFlightsFromName(const Airline* pComp);
void	doPrintFlightsWithPlaneCode(const Airline* pComp);
void	doPrintFlightsWithPlaneType(const Airline* pComp);

int		saveAirlineToFile(const Airline* pComp, const char* fileName,int compressIndictor);
int		loadAirlineFromFile(Airline* pComp, const AirportManager* pManager, const char* fileName, int compressIndictor);
int		writeAirLineToBinaryFileCompress(const char * fileName, const Airline* pAirline);
int		readAirLineFromBinaryFileCompress(const char * fileName, Airline* pAirline);
void	sortFlight(Airline* pComp);
void	findFlight(const Airline* pComp);

int		initDateList(Airline* pComp);
int		insertFlightDateToList(LIST* lst, Flight* pFlight);
NODE*	insertDateToList(NODE* pNode,Date* pDate);

void	freeFlightArr(Flight** arr, int size);
eSortOption showSortMenu();
void	freeCompany(Airline* pComp);

#endif

