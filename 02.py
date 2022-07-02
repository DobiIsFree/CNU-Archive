def my_bgr2gray(src):
    B, G, R = src[:, :, 0], src[:, :, 1], src[:, :, 2]

    dst1 = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)

    #dst2는 B,G,R 채널 각각 1/3씩 사용
    dst2 = (B / 3) + (G / 3) + (R / 3)
    dst2 = (dst2+0.5).astype(np.uint8)

    #B,G,R 중 하나의 채널만 사용
    dst3 = B

    #공식 사용
    dst4 = 0.2125 * R + 0.7154 * G + 0.0721 * B
    dst4 = (dst4 + 0.5).astype(np.uint8)

    return dst1, dst2, dst3, dst4
