
/* Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
 *
 * Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums. */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node_s
{
	int data;
	int freq;
	int start_index;
	int end_index;
	struct node_s *left;
	struct node_s *right;
}node_t;

int degree_max = 0;
int degree_val = -1;
int min_subarray_len = INT_MAX;

node_t *create_node(int data, int index)
{
	node_t *temp = NULL;
	temp = (node_t *)malloc(sizeof(node_t));
	memset(temp, 0, sizeof(node_t));
	temp->data = data;
	temp->freq = 1;
	temp->start_index = index;
	temp->end_index = index;
	return temp;
}

void update_degree(int data, int count)
{
	if(count < degree_max)
		return;

	degree_max = count;
	degree_val = data;
}

node_t *insert_into_tree(node_t *root, int data, int index)
{
	node_t *temp = NULL;
	node_t *prev = NULL;

	int found = 0;

	if(root == NULL)
	{
		root = create_node(data, index);
		update_degree(data, 1);
        return root;
	}

	temp = root;

	while(temp != NULL)
	{
		if(temp->data == data)
		{
			temp->freq++;
			temp->end_index = index;
			update_degree(data, temp->freq);
			found = 1;
			break;
		}
		else
		{
			prev = temp;
			if(temp->data < data)
				temp = temp->right;
			else
				temp = temp->left;
		}
	}

	if(found == 0)
	{
		if(prev == NULL)
		{
			printf("Error case should not happen\n");
			return NULL;
		}

		if(data > prev->data)
			prev->right = create_node(data, index);
		else
			prev->left = create_node(data, index);

		update_degree(data, 1);
	}

	return root;
}


void print_tree(node_t *root)
{
	if(root == NULL)
		return;

	printf("Val : %d, Deg : %d, start_index : %d, end_index : %d\n", root->data, root->freq, root->start_index, root->end_index);

	print_tree(root->left);
	print_tree(root->right);

}

void update_len_min_subarray(node_t *root)
{
	if(root->freq == degree_max)
	{
		if(min_subarray_len > (root->end_index - root->start_index + 1))
			min_subarray_len = (root->end_index - root->start_index + 1);
	}
	return;
}

void calculate_min_subarray(node_t *root)
{
	if(root == NULL)
		return;

	update_len_min_subarray(root);
	calculate_min_subarray(root->left);
	calculate_min_subarray(root->right);
}

node_t * find_node(node_t *root, int data)
{
	node_t *temp = NULL;

	if(root == NULL)
		return NULL;

	temp = root;

	while(temp != NULL)
	{
		if(temp->data == data)
			return temp;
		else
		{
			if(temp->data < data)
				temp = temp->right;
			else
				temp = temp->left;
		}
	}

	return NULL;
}

int findShortestSubArray(int* nums, int numsSize){

    int i = 0;
    degree_max = 0;
    degree_val = -1;
    min_subarray_len = INT_MAX;
    
    node_t *root = NULL;
    
    for( i = 0; i < numsSize; i++)
	{
        printf("Inserting : %d\n", nums[i]);
		root = insert_into_tree(root, nums[i], i);
	}
    
    print_tree(root);

    printf("\n Max Degree : %d , Max Val : %d\n", degree_max, degree_val);
    
    calculate_min_subarray(root);
    
    return min_subarray_len;
}
