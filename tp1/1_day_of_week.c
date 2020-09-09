#include <stdio.h>

int main() {
    fflush(stdin);

    int day, month, year;
    printf("Enter day: ");
    scanf("%d", &day);  
    printf("Enter month: ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    if (day < 0 || day > 31 || month < 0 || month > 12 || year < 1582) {
        printf("Invalid date");
        return 1;
    } else if (month == 1 || month == 2) {
        month += 12;
        year--;
    }

    int s = year / 100;

    int JD;
    JD = 1720996.5 - s + (s/4) + (365.25*year) + (30.6001*(month+1)) + day;
    JD = JD - (JD/7)*7;

    int JS;
    JS = JD % 7;

    printf("%d\n", JS);

    char * day_of_week[]  = {"Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday"};

    printf("%s\n", day_of_week[JS]);
    return 0;
}