
int		main()
{
	char * m;
	m = malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	free(m);
	show_alloc_mem();
	return (0);
}
