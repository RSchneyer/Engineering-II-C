void createFileHeader(int dateArray[]);
void createFileFooter(int dateArray[], double currentBalance);
void logAccountEvent(int eventType, double balanceChange, double currentBalance);
void printMenu();
void initAccount(double *initDepositAndAPR);
void closeAccount(double finalBalance);

double changeBalance(int promptType, double currentBalance);
double calculateInterest(double balance, double apr);

int getMenuSelection();
int checkDay(int month, int day);