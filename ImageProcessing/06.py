def get_DoG_filter(fsize, sigma=1):
    # TODO
    y,x = np.mgrid[-(fsize//2):(fsize//2)+1, -(fsize//2):(fsize//2)+1]

    DoG_x = (-x/sigma**2) * np.exp(-((x**2 + y**2)/(2*sigma**2)))
    DoG_y = (-y/sigma**2) * np.exp(-((x**2 + y**2)/(2*sigma**2)))

    # filter의 총 합 0으로 만들기
    DoG_x = DoG_x - (DoG_x.sum()/fsize**2)
    DoG_y = DoG_y - (DoG_y.sum() / fsize ** 2)

    return DoG_x, DoG_y

# TODO
# dst_x, dst_y를 사용하여 magnitude 계산
# dst = np.sqrt(dst_x**2 + dst_y**2)
