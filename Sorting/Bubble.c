/*
 * Bubble.c
 * 
 * Copyright 2020 Mayank Kabra
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
 
#include <stdio.h>

void print (int *, int);
void bubble (int *, int);

void print (int *A, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void bubble (int *A, int size) {
	int i;
	int swapped;
	int temp;
	int reach;
	
	swapped = 1;
	reach = size - 1;
	
	while (swapped == 1) {
		swapped = 0;
		i = 0;
		while (i < reach) {
			if (A[i] > A[i + 1]) {
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
		reach--;
	}
}

int main (int argc, char **argv) {
	int A[] = {4, 1, 5, 7, 9, 2, 0, 3, 8, 6};
	int size = sizeof(A)/sizeof(A[0]);
	
	printf("The UNSORTED array is  : ");
	print(A, size);
	
	printf("\nPerforming bubble sort.");
	bubble(A, size);
	
	printf("\nThe SORTED array is    : ");
	print(A, size);
	
	return 1;
}

