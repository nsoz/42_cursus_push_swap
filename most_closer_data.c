// bu fonksiyon b listesindeki verilere bakarak ilgili a datatsıdan küüçük en büyük sayıyı bulur 

int	ft_ctrl(int	*arr)
{
	int index;

	index = 0;
	while
}

int	most_closer_data(int a_data, t_lst *b_list)
{
	int 	*arr;
	int		index_of_arr;
	int 	len_b;
	t_lst	*iter;

	index_of_arr = 0;
	len_b = ft_lst_size(b_list);
	arr = (int *)malloc(len_b * sizeof(int));
	while (iter != NULL)
	{
		arr[index_of_arr] = (a_data - (iter->data))
		iter = iter->next;
		index_of_arr++;
	}
	ft_ctrl(arr, (index_of_arr - 1));
	// arr içerisindeki + değerlerin en küçüğünün indexini + 1 vererek döndür 
	// +1 in sebebi listlerin datalarını 1 den başlayakrak sayarken arr 0 dan başlamakta
}
