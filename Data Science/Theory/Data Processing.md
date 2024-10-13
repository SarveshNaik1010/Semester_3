
# **Data Science Documentation**  

## **Subject: Data Science (B.Tech)**  

---

## **Chapter: Data Processing**

### **1. Introduction**
Data processing refers to techniques used to transform raw data into a meaningful format. This process involves cleansing, organizing, transforming, and aggregating data to enable analysis and visualization. In Python, popular libraries for data processing include:  
- **Pandas**: Provides fast, flexible data structures like DataFrames for data manipulation.  
- **NumPy**: Supports large, multi-dimensional arrays and matrix operations.  
- **Others**: Libraries such as `openpyxl` (for Excel), `json` (for JSON), and `nltk` (for text processing).

---

### **2. Data Cleansing Operations**
Data often contains missing, inconsistent, or erroneous values, requiring cleaning to ensure analysis accuracy. Here are some common operations:

- **Handling Missing Data**:  
  ```python
  import pandas as pd

  df = pd.read_csv('data.csv')
  df.fillna(0, inplace=True)  # Replace NaN with 0
  df.dropna(inplace=True)  # Drop rows with missing values
  ```

- **Removing Duplicates**:  
  ```python
  df.drop_duplicates(inplace=True)
  ```

- **Correcting Data Types**:  
  ```python
  df['Date'] = pd.to_datetime(df['Date'])
  df['Price'] = pd.to_numeric(df['Price'])
  ```

---

### **3. Processing CSV Data**
CSV (Comma-Separated Values) files are commonly used to store tabular data.  

- **Reading CSV File**:  
  ```python
  df = pd.read_csv('data.csv')
  print(df.head())  # Display the first 5 rows
  ```

- **Writing to CSV File**:  
  ```python
  df.to_csv('processed_data.csv', index=False)
  ```

---

### **4. Processing JSON Data**
JSON (JavaScript Object Notation) is a popular format for storing structured data.  

- **Reading JSON File**:  
  ```python
  import json
  import pandas as pd

  with open('data.json') as f:
      data = json.load(f)
  df = pd.json_normalize(data)
  ```

- **Writing to JSON File**:  
  ```python
  df.to_json('output.json', orient='records', lines=True)
  ```

---

### **5. Processing XLS Data**
Microsoft Excel files can be processed using Pandas and openpyxl libraries.

- **Reading Excel File**:  
  ```python
  df = pd.read_excel('data.xlsx', sheet_name='Sheet1')
  ```

- **Writing to Excel File**:  
  ```python
  df.to_excel('output.xlsx', index=False)
  ```

---

### **6. Data Wrangling**
Data wrangling is the process of converting raw data into a suitable format for analysis.

- **Merging DataFrames**:  
  ```python
  df1 = pd.DataFrame({'ID': [1, 2], 'Name': ['Alice', 'Bob']})
  df2 = pd.DataFrame({'ID': [1, 2], 'Score': [90, 80]})
  merged_df = pd.merge(df1, df2, on='ID')
  ```

- **Reshaping Data (Pivot)**:  
  ```python
  df.pivot_table(values='Score', index='ID', aggfunc='mean')
  ```

---

### **7. Data Aggregation**
Aggregation involves summarizing data by grouping.

- **Grouping Data**:  
  ```python
  df.groupby('Category').sum()
  ```

- **Calculating Aggregate Statistics**:  
  ```python
  df['Price'].mean()
  df['Quantity'].sum()
  ```

---

### **8. Word Tokenization**
Tokenization splits text into individual words or tokens for text processing.

- **Using NLTK for Tokenization**:  
  ```python
  from nltk.tokenize import word_tokenize

  text = "Data science is fascinating!"
  tokens = word_tokenize(text)
  print(tokens)
  ```

---

### **9. Stemming and Lemmatization**
These are used to reduce words to their root form for natural language processing (NLP).

- **Stemming**:  
  ```python
  from nltk.stem import PorterStemmer

  ps = PorterStemmer()
  print(ps.stem('running'))  # Output: 'run'
  ```

- **Lemmatization**:  
  ```python
  from nltk.stem import WordNetLemmatizer

  lemmatizer = WordNetLemmatizer()
  print(lemmatizer.lemmatize('running', pos='v'))  # Output: 'run'
  ```

---
