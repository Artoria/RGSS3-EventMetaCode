  cmd(101);
  start();
    entity("脸图", "string");
    entity("编号", "number");
    enumcase("窗口背景", "普通窗口", "透明背景", "暗色窗口", end_item());
    enumcase("窗口位置", "居上", "居中", "居下", end_item());
  stop();
  
  cmd(102);
  start();
    entity("选项", "stringlist");
    enumcase("取消的情况", "无效", "选项1", "选项2", "选项3", "选项4", end_item());
  stop();
  
  cmd(103);
  start();
    entity("接受数值的变量", "var");
    entity("最大数码", "number");
  stop();
  
  cmd(104);
  start();
    entity("接受物品的变量", "var");
    entity("最大数码", "number");
  stop();
  
  cmd(105);
  start();
    entity("卷动速度", "number");
    enumcase("快进", "可以", "不可", end_item());
  stop();
  
  cmd(108);
  start();
    entity("注释", "string");
  stop();
  
  cmd(111);
  start();
    selectcase("开关", "变量", "独立开关", "计时器", "角色", "敌人", "事件", "物品", "武器", "护甲", "按下按钮", "脚本", "载具", end_item());
      start();
        casewhen(0); 
          start();
            entity("开关编号", "switch");
            enumcase("被", "关闭", "打开",  end_item());
          stop();
        
        casewhen(1);
          start();
            entity("变量编号", "var");
            
            selectcase("常量", "变量", end_item());#2
            start();#3
              casewhen(0); start(); entity("常量", "number") stop(); 
              casewhen(1); start(); entity("变量", "var") stop();
            stop();
            
            #4
            enumcase("关系", "等于", "以上", "以下", "大于", "小于", "不等于", end_item());
          stop();
          
        casewhen(2);
        start();
           entity("独立开关名", "selfswitch");
           enumcase("被", "关闭", "打开", end_item());
        stop();
        
        casewhen(3);
        start();
           enumcase("计时器的时间", "不小于", "不大于", end_item());
           entity("时间", "number");
        stop();
        
        casewhen(4);
        start();
           selectcase("在队伍时", "名字是", "职业是", "技能学会", "武器装备", "防具装备", "状态有", end_item());
           start();
            casewhen(1); start(); entity("名字", "string"); stop();
            casewhen(2); start(); entity("职业", "class"); stop();
            casewhen(3); start(); entity("技能", "skill"); stop();
            casewhen(4); start(); entity("武器", "weapon"); stop();
            casewhen(5); start(); entity("防具", "armor"); stop();
            casewhen(6); start(); entity("状态", "state"); stop();
           stop();
        stop();
        
        casewhen(5);
        start();
          entity("敌人", "enemy_index");
          selectcase("在", "出现", "状态是");
          start();
            casewhen(1); start(); entity("状态", "state"); stop();
          stop();
        stop();
        
        casewhen(6);
        start();
          entity("事件", "map_event");
          entity("面向", "direction");
        stop();
         
      
      stop();
  stop();
