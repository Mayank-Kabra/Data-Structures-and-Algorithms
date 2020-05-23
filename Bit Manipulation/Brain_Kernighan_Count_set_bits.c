/*
 * Brain_Kernighan_Count_set_bits.c
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

int count_set_bits (int);

int count_set_bits (int num) {
	int count = 0;
	
	while (num) {
		count++;
		num = num & (num-1);
	}
	
	return count;
}

int main(int argc, char **argv)
{
	int number = 65;
	int number_set_bits;
	
	number_set_bits = count_set_bits(number);
	
	printf("The number of set bits in %d is %d", number, number_set_bits);
	
	return 0;
}

