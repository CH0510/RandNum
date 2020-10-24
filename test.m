gaussian_data = load("C:\Users\hp\Desktop\homework\gaussianData.txt");
figure(1)
subplot(311);
histogram(gaussian_data(1:10000),100);
title('N(0,1)');xlim([-16 16]);
subplot(312)
histogram(gaussian_data((1:10000)+10000),100);
title('N(0,4.26)');xlim([-16 16]);
subplot(313)
histogram(gaussian_data((1:10000)+20000),100);
title('N(-2.5,1)');xlim([-16 16]);
rayleigh_data = load("C:\Users\hp\Desktop\homework\rayleighData.txt");
figure(2);
subplot(311);
histogram(rayleigh_data(1:10000),100);
title('Rayleigh(1)');axis([0 15 0 500])
subplot(312)
histogram(rayleigh_data((1:10000)+10000),100);
title('Rayleigh(0.36)');axis([0 15 0 500])
subplot(313)
histogram(rayleigh_data((1:10000)+20000),100);
title('Rayleigh(3.4)');axis([0 15 0 500])
poisson_data = load("C:\Users\hp\Desktop\homework\poissonData.txt");
figure(3);
subplot(411);
histogram(poisson_data(1:10000),100);
title('Poisson(0.2)');xlim([0 20])
subplot(412)
histogram(poisson_data((1:10000)+10000),100);
title('Poisson(1)');xlim([0 20])
subplot(413)
histogram(poisson_data((1:10000)+20000),100);
title('Poisson(6)');xlim([0 20])
subplot(414)
histogram(poisson_data((1:10000)+30000),100);
title('Poisson(10)');xlim([0 20]);
U01_data = load("C:\Users\hp\Desktop\homework\U01Data.txt");
figure(4);
histogram(U01_data,1000);
title('U(0,1)')
xlim([0 1])