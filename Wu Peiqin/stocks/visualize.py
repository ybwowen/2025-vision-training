import matplotlib.pyplot as plt

# 读取数据
def read_data(filename):
    with open(filename, 'r') as file:
        data = [float(line.strip()) for line in file]
    return data

# 读取预测结果
def read_predictions(filename):
    with open(filename, 'r') as file:
        predictions = [float(line.strip()) for line in file]
    return predictions

# 主函数
def main():
    # 读取输入数据和预测结果
    input_data = read_data('dollar.txt')
    predictions = read_predictions('predictions.txt')

    # 创建时间轴
    days = list(range(1, len(input_data) + 1))
    future_days = list(range(len(input_data) + 1, len(input_data) + 1 + len(predictions)))

    # 绘制图表
    plt.figure(figsize=(10, 6))
    plt.plot(days, input_data, label='Input Data', marker='o')
    plt.plot(future_days, predictions, label='Predictions', marker='x')
    plt.xlabel('Days')
    plt.ylabel('Exchange Rate')
    plt.title('USD Exchange Rate Prediction')
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == '__main__':
    main()