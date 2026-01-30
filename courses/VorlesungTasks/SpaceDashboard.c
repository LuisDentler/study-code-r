#include<stdio.h>



int main() {
char class[21] = ""; 
int crew_count = 0;
int mission_days = 0;
const long travel_distance = 40000;
const float light_speed_distance = 12.7;
const double current_range = 1114445.225; 

printf("Wie lautet die Space-Shuttle Klasse?\n");
scanf("%19s", class);
printf("Wie viele Crew Mitglieder gibt es?\n");
scanf("%d",  &crew_count);
printf("Wie viele Missionstage sind geplant?\n");
scanf("%d",  &mission_days);

printf("%-25s %s\n", "Name", "Value");
printf("------------------------------------------\n");
printf("%-25s %s\n", "Class", class);
printf("%-25s %d\n", "crew_count", crew_count);
printf("%-25s %d\n", "mission_days", mission_days);
printf("%-25s %ld\n", "travel_distance", travel_distance);
printf("%-25s %.2f\n", "light_speed_distance", light_speed_distance);
printf("%-25s %.3f\n", "current_range", current_range);
}