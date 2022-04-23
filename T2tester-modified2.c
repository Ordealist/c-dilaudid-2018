#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int dsgnp;
time_t current_time;
time_t new_time;
struct tm * time_info1;
struct tm time_info2;

char timeString1[9];
char timeString2[9];

int hh;
int diffh;
int mm;
int diffm;
int hours;
int minutes;
time_t hrt;
int usrpn;

main(void) {
  printf("Dilaudid (r)\n");

  current_time = time(NULL);
  time_info1 = localtime( & current_time);

  strftime(timeString1, sizeof(timeString1), "%H:%M", time_info1);
  puts(timeString1);

  printf("Please choose a dosage of Dilaudid, you may choose 1 or 2 milligrams.\n");
  scanf("%d", & dsgnp);

  if (dsgnp == 1) {
    printf("Last dosage time (1 or 2mg)? Enter hour in 24-hour time format.\n");
    scanf("%d", & hh);
    printf("Enter Minute\n");
    scanf("%d", & mm);

    time_info2 = * time_info1;
    time_info2.tm_hour = hh;
    time_info2.tm_min = mm;
    time_info2.tm_sec = 0;

    new_time = mktime( & time_info2);
    int diff = new_time - current_time;

    diffh = -1 * ((diff / 3600) % 24);
    diffm = -1 * ((diff / 60) % 60);

    printf("The difference between the time you entered and the current time is: %d hours and %d minutes.\n", diffh, diffm);

    if (diffh > 12) {
      printf("You are safe to take 1mg.\n");
    }
    else if (diffh <= 12) {
      printf("Your last dosage of 1 or 2 mg was 12 hours ago or less. It is unsafe to take any right now.\n");
    }
    //printf("If you are planning on studying or working in the next three hours, it is not advised to take any dosage.\n");

  }
  if (dsgnp == 2) {

    printf("Comparative Pain Scale\n"
      "10 - Unable to move\n"
      "9 - Severe\n"
      "8 - Intense\n"
      "7 - Unmanageable\n"
      "6 - Distressing\n"
      "5 - Distracting\n"
      "4 - Moderate\n"
      "3 - Uncomfortable\n"
      "2 - Mild\n"
      "1 - Minimal\n"
      "0 - No pain\n"
    );
    printf("Please enter your self-assessed level of pain: ");

    scanf("%d", &usrpn);
    if (usrpn > 5) {
      printf("You can take 2mg of Dilaudid.\n");
    } else {
      printf("Last dosage time (1 or 2mg)? Enter hour in 24 hour format.\n");
      scanf("%d", & hh);
      printf("Enter Minute\n");
      scanf("%d", & mm);

      time_info2 = * time_info1;
      time_info2.tm_hour = hh;
      time_info2.tm_min = mm;
      time_info2.tm_sec = 0;

      new_time = mktime( & time_info2);
      int diff = new_time - current_time;

      diffh = -1 * ((diff / 3600) % 24);
      diffm = -1 * ((diff / 60) % 60);

      printf("The difference between the time you entered and the current time is: %d hours and %d minutes.\n", diffh, diffm);
      if (diffh > 12) {
        printf("You can take 2mg.\n");
      } else if (diffh <= 12) {
      printf("Your last dosage of 1 or 2 mg was 12 hours ago or less. It is unsafe to take any right now.\n");

      printf("If you are planning on studying or working in the next three hours, it is not advised to take any dosage.\n");
      }
    }
  }
  return 0;
}
