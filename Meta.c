cmd(111);
start();
    selectcase("开关", "变量", "独立开关", "计时器", "角色", "敌人", "事件", "物品", "武器", "护甲", "按下按钮", "脚本", "载具", end_item());
      start();
        casewhen(0); 
          start();
            switchid();
            enumcase("打开", "关闭");
          stop();
        
        casewhen(1);
          start();
            varid();  
            
            selectcase("直接指定", "变量指定", end_item());
            start();#3
              casewhen(0); start(); number(); stop(); 
              casewhen(1); start(); varid (); stop();
            stop();
            
            enumcase("等于", "以上", "以下", "大于", "小于", "不等于", end_item());
            
          stop();
      stop();
  stop();
