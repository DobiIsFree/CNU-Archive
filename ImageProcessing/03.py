def my_calcHist(img):
    hist = np.zeros(256)
    (height, width) = img.shape
    for h in range(height):
        for w in range(width):
            hist[img[h,w]] += 1

    return hist

def my_normalize_hist(hist, pixel_num):
    return hist/pixel_num

def my_PDF2CDF(pdf):
    pdf_len = pdf.shpae[0]
    cdf = np.zeros((pdf_len, ))
    cdf[0] = pdf[0]
    for i in range(1, pdf_len):
        cdf[i] = pdf[i] + cdf[i-1]
    return cdf

def my_denormalize(normalized, gray_level):
    return normalized * gray_level

def my_calcHist_equalization(denormalized, hist):
    hist_equal = np.zeros(denormalized.shape).astype('int')
    for i in range(len(hist_equal)):
        hist_equal[denormalized[i]] += hist[i]
    return hist_equal





