// https://m.blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=xxxstarxxx&logNo=221826768233&categoryNo=49&proxyReferer=
// https://boycoding.tistory.com/164

int	make_rgb(int r, int g, int b)
{
	return (0xFFFFFF & (r << 16 | g << 8 | b));
}

int	get_r(int rgb)
{
    rgb = rgb & 0x00ff0000;  // red 비트에서 &(논리곱)
    rgb = rgb >> 16;
    return rgb;
}

int	get_g(int rgb)
{
    rgb = rgb & 0x0000ff00;  // green 비트에서 &(논리곱)
    rgb = rgb >> 8;
    return rgb;
}

int	get_b(int rgb)
{
    rgb = rgb & 0x000000ff;  // blue 비트에서& (논리곱)
    rgb = rgb >> 0;
    return rgb;
}