/*
 * Merge.c
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
#include <stdlib.h>

void print (int *, int);
void merge (int *, int, int, int);
void merge_sort (int *, int, int);

void print (int *A, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void merge (int *A, int low, int mid, int high) {
	int lenL, lenR;
	int i, j, k;
	int *left_arr = (int *) calloc((mid - low), sizeof(int));
	int *right_arr = (int *) calloc((high - mid), sizeof(int));
	int itr;
	
	lenL = mid - low;
	lenR = high - mid;
	i = 0;
	j = 0;
	k = low;
	
	for (itr = low; itr < mid; itr++) {
		left_arr[itr - low] = A[itr];
	}
	
	for (itr = mid; itr < high; itr++) {
		right_arr[itr - mid] = A[itr];
	}
	
	while (i < lenL && j < lenR) {
		if (left_arr[i] < right_arr[j]) {
			A[k] = left_arr[i];
			i++;
		} else {
			A[k] = right_arr[j];
			j++;
		}
		k++;
	}
	
	while (i < lenL) {
		A[k] = left_arr[i];
		i++;
		k++;
	}
	
	while (j < lenR) {
		A[k] = right_arr[j];
		j++;
		k++;
	}
	
}

void merge_sort (int *A, int low, int high) {
	int mid;
	
	if ((high - low) < 2) {
		return;
	}
	
	mid = low + (high - low) / 2;
	
	merge_sort (A, low, mid);
	merge_sort (A, mid, high);
	merge(A, low, mid, high);
	
}

int main (int argc, char **argv) {
	int A[] = {4, 1, 5, 7, 9, 2, 0, 3, 8, 6};
	int size = sizeof(A)/sizeof(A[0]);
	
	printf("The UNSORTED array is  : ");
	print(A, size);
	
    printf("\nPerforming merge sort.");
	merge_sort(A, 0, size);
	
	printf("\nThe SORTED array is    : ");
	print(A, size);
	
	return 1;
}

