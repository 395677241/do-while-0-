int32_t AudioInitI2s(void)
{
	int32_t ret = OK;
    int32_t devmemFd = -1;
	
	do
	{
		devmemFd = open("/dev/mem", O_RDWR | O_SYNC);
	    if (devmemFd == -1) 
		{
	        printf("i2s open /dev/mem failed!\n");
			ret = ERROR;
			break;
	    }   

	    s_pI2sBaseAddr = (uint8_t *)mmap(NULL, I2S_MAP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, devmemFd, I2S_BASE_ADDR);
	    if (s_pI2sBaseAddr == MAP_FAILED) 
		{
	        printf("i2s mmap failed!\n");
			ret = ERROR;
			break;
	    }

		close(devmemFd);
	}while(0);

    return ret;
}

