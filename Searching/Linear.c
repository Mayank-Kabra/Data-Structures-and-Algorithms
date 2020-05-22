/*
 * Linear.c
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

int linear(int *, int, int);

int linear(int *A, int size, int num) {
	int i;
	
	for (i = 0; i < size; i++) {
		if (A[i] == num) {
			return i;
		}
	}
	return -1;
}

int main(int argc, char **argv)
{
	int A[] = {4, 1, 5, 7, 9, 2, 0, 3, 8, 6};
	int query = 8;
	int size = sizeof(A) / sizeof(A[0]);
	
	int index = linear(A, size, query);
	
	if (index == -1) {
		printf("The number %d was not found in the array.", query);
	} else {
		printf("The number %d was found at position %d in the array.", query, (index + 1));
	}
	
	return 0;
}

