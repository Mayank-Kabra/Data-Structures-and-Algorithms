/*
 * Binary.c
 * 
 * Copyright 2020 Mayank Kabra <mayank@Mayank>
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

int binary (int *, int, int);

int binary (int *A, int size, int num) {
	int low = 0;
	int high = size - 1;
	int mid;
	
	while (low <= high) {
		mid = low + ((high - low) / 2);
		
		if (A[mid] == num) {
			return mid;
		} else if (num < A[mid]) {
			high = mid - 1;
		} else if (num > A[mid]) {
			low = mid + 1;
		}
	}
	
	return -1;
}

int main (int argc, char **argv)
{
	int A[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int query = 60;
	int size = sizeof(A) / sizeof(A[0]);
	
	int index = binary(A, size, query);
	
	if (index == -1) {
		printf("The number %d was not found in the array.", query);
	} else {
		printf("The number %d was found at position %d in the array.", query, (index + 1));
	}
	
	return 0;
}
