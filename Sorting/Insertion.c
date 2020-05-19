/*
 * Insertion.c
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
void Insertion (int *, int);

void print (int *A, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	
}

void Insertion (int *A, int size) {
	int i;
	int curr_num;
	int curr_pos;
	
	for(i = 0; i < size; i++) {
		curr_num = A[i];
		curr_pos = i;
		while(curr_pos > 0 && A[curr_pos-1] > curr_num) {		// checking if shift is neede or not
			A[curr_pos] = A[curr_pos-1];		//shifting 1 position to right. 
			curr_pos--;
		}
		A[curr_pos] = curr_num;			// place surrent item to its desired place.
	}
	
}

int main (int argc, char **argv) {
	int A[] = {4, 1, 5, 7, 9, 2, 0, 3, 8, 6};
	int size = sizeof(A)/sizeof(A[0]);
	
	printf("The UNSORTED array is  : ");
	print(A, size);
	
	printf("\nPerforming insertion sort.");
	Insertion(A, size);
	
	printf("\nThe SORTED array is    : ");
	print(A, size);
	
	return 1;
}
