#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[50];
  char firstPlaceRaceCarColor[25];
};
struct RaceCar {
  char driverName[50];
  char raceCarColor[25];
  int totalLapTime;
};

// Print functions section
void printIntro() {
  printf("Welcome to our main event digital race fans! I hope everybody has their snacks because we are about to begin!\n\n");
}
void countDown() {
  printf("Racers Ready! In...\n\n");
  for (int i = 1; i <= 5; i++) printf("%i\n\n", i);
  printf("Race!\n\n");
}
void printFirstPlaceAfterLap(struct Race *race) {
  printf("After lap number %d\nFirst Place Is: %s in the %s race car!\n", 
         race -> currentLap, race -> firstPlaceDriverName, race -> firstPlaceRaceCarColor);
}
void printCongragulations(struct Race *race) {
  printf("Let's all congratulate %s in the %s race car for an amazing performance. It truly was a great race and everybody have a goodnight!\n", race -> firstPlaceDriverName, race -> firstPlaceRaceCarColor);
}

// Logic functions section
int calculateTimeToCompleteLap() {
  int speed = (rand() % 3);
  int acceleration = (rand() % 3);
  int nerves = (rand() % 3);
  return speed + acceleration + nerves;
}
void updateRaceCar(struct RaceCar *raceCar) {
  raceCar -> totalLapTime += calculateTimeToCompleteLap();
}
void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
  if (raceCar1 -> totalLapTime <= raceCar2 -> totalLapTime) {
    strcpy(race -> firstPlaceDriverName, raceCar1 -> driverName);
    strcpy(race -> firstPlaceRaceCarColor, raceCar1 -> raceCarColor);
  } else {
    strcpy(race -> firstPlaceDriverName, raceCar2 -> driverName);
    strcpy(race -> firstPlaceRaceCarColor, raceCar2 -> raceCarColor);
  }
}

// Start race
void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
  struct Race race = {5, 1, "", ""};

  for (int i = 1; i <= race.numberOfLaps; i++) {
    race.currentLap = i;

    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);

    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(&race);
  }
  printCongragulations(&race);
}

int main() {

  struct Race r1 = {5, 1, "Josue", "Black"};
  struct RaceCar r2 = {"Kal", "Green", 3};
  struct RaceCar r3 = {"Jan", "Purple", 4};

  printIntro();
  countDown();

  startRace(&r2, &r3);

  // printFirstPlaceAfterLap(&r1);

  srand(time(0));

}
