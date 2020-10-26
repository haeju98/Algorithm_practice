#include <stdlib.h> // atoi, rand, malloc, realloc
#include <stdio.h>
#include <time.h> //time
#include <math.h>

typedef struct
{
    int x;
    int y;
} t_point;


double find_closest_pair(t_point *points, int num_point) {
  int i, j;
  double d = 10000000.00;
  double x_dist, y_dist, dist;

  for(i=0; i<=num_point-2; i++) {
      for(j=i+1; j<=num_point-1; j++) {
          x_dist = (double)pow(points[i].x-points[j].x, 2);
          y_dist = (double)pow(points[i].y-points[j].y, 2);
          printf("{%d, %d}, {%d, %d}\n", points[i].x, points[i].y, points[j].x, points[j].y);
          printf("x_dist: %.2f, y_dist: %.2f\n", x_dist, y_dist);
          dist = sqrt(x_dist+y_dist);

          if(d > dist)
            d = dist;
            printf("new_dist: %.2f\n\n", d);
      }
  }

  return d;
}


void main(int argc, char **argv) {
    int x, y;
	int num_point; // number of points
	
	if (argc != 2)
	{
		printf( "%s number_of_points\n", argv[0]);
		return 0;
	}

	num_point = atoi( argv[1]);
	if (num_point <= 0)
	{
		printf( "The number of points should be a positive integer!\n");
		return 0;
	}

	t_point *points = (t_point *) malloc( num_point * sizeof( t_point));

	// making n points
	srand(time(NULL));
	for (int i = 0; i < num_point; i++)
	{
		x = rand() % 10 + 1; // 1 ~ RANGE random number
		y = rand() % 10 + 1;
		
		points[i].x = x;
		points[i].y = y;
 	}

	fprintf(stderr, "%d points created!\n\n", num_point);

    printf("smallest distance: %.2f\n", find_closest_pair(points, num_point));
}