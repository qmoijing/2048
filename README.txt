# pd2-2048
Bonus:1.Back鍵:恢復移動前情形
      2.Best:最高紀錄
#Report
UML:

game
------------------------------------------------
-Square[4][4:int
-Score:int
-Best:int
-old_Square[4][4]:int
-old_Score:int
------------------------------------------------
+game(*parent: QWidget): explicit
-on_pushButton_clicked():void
-on_pushButton_2_clicked():void
-on_pushButton_3_clicked():void
# keyPressEvent(*event: QKeyEvent): virtual void 
-checkWin():char
-display():void
-score():void
-best():void
