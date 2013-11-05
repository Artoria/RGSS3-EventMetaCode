cmd("显示文章", 101);
  start();
    entity("脸图", "string");
    entity("编号", "number");
    enumcase("窗口背景", "普通窗口", "透明背景", "暗色窗口", end_item());
    enumcase("窗口位置", "居上", "居中", "居下", end_item());
  stop();
  
  cmd("选项", 102);
  start();
    entity("选项", "stringlist");
    enumcase("取消的情况", "无效", "选项1", "选项2", "选项3", "选项4", end_item());
  stop();
  
  cmd("数值输入", 103);
  start();
    entity("接受数值的变量", "var");
    entity("最大数码", "number");
  stop();
  
  cmd("物品选择", 104);
  start();
    entity("接受物品的变量", "var");
    entity("最大数码", "number");
  stop();
  
  cmd("滚动字幕", 105);
  start();
    entity("卷动速度", "number");
    enumcase("快进", "是", "否", end_item());
  stop();
  
  cmd("注释", 108);
  start();
    entity("注释", "string");
  stop();
  
  cmd("条件分歧", 111);
  start();
    selectcase("开关", "变量", "独立开关", "计时器", "角色", "敌人", "事件", "物品", "武器", "护甲", "按下按钮", "脚本", "载具", end_item());

        casewhen(0); 
          start();
            entity("开关编号", "switch");
            enumcase("被",  "打开", "关闭",  end_item());
          stop();
        
        casewhen(1);
          start();
            entity("变量编号", "var");
            selectcase("常量", "变量", end_item());
              casewhen(0); start(); entity("常量", "number"); stop(); 
              casewhen(1); start(); entity("变量", "var"); stop();
            enumcase("关系", "等于", "以上", "以下", "大于", "小于", "不等于", end_item());
          stop();
          
        casewhen(2);
        start();
           entity("独立开关名", "selfswitch");
           enumcase("被", "打开", "关闭",  end_item());
        stop();
        
        casewhen(3);
        start();
           enumcase("计时器的时间", "不小于", "不大于", end_item());
           entity("时间", "number");
        stop();
        
        casewhen(4);
        start();
           selectcase("在队伍时", "名字是", "职业是", "技能学会", "武器装备", "防具装备", "状态有", end_item());
            casewhen(1); start(); entity("名字", "string"); stop();
            casewhen(2); start(); entity("职业", "class"); stop();
            casewhen(3); start(); entity("技能", "skill"); stop();
            casewhen(4); start(); entity("武器", "weapon"); stop();
            casewhen(5); start(); entity("防具", "armor"); stop();
            casewhen(6); start(); entity("状态", "state"); stop();
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
         
        casewhen(7);
        start();
          entity("值", "number");
          enumcase("比较", "以上", "以下", "低于", end_item());
        stop();
      
        casewhen(8);
        start();
          entity("物品", "item");
        stop();
        
        casewhen(9);
        start();
          entity("武器", "weapon");
          enumcase("包含已装备的", "否", "是", end_item());
        stop();
        
        casewhen(10);
        start();
          entity("防具", "weapon");
          enumcase("包含已装备的", "否", "是", end_item());
        stop();
        
        casewhen(11);
        start();
          entity("按钮", "symbol");
        stop();
        
        casewhen(12);
        start();
          entity("脚本", "string");
        stop();
        
        casewhen(13);
        start();
          entity("载具", "vehicle");
        stop();
        
        

  stop();
  
  cmd("调用公共事件", 117);
  start();
    entity("公共事件", "commonevent");
  stop();
  
  cmd("标签跳转", 119);
  start();
    entity("标签名", "string");
  stop();
  
  cmd("开关操作", 121);
  start();
    entity("从", "switch");
    entity("到", "switch");
    enumcase("操作", "打开", "关闭", end_item());
  stop();
  
  cmd("变量操作", 122);
  start();
    entity("从", "var");
    entity("到", "var");
    enumcase("操作", "代入", "加上", "减去", "乘以", "除以", "取余", end_item());
    selectcase("常量", "变量", "随机数", "游戏数据", "脚本");
      casewhen(0); start(); entity("常数", "number"); stop();      
      casewhen(1); start(); entity("变量", "var"); stop();
      casewhen(2); start(); entity("随机数", "number");entity("随机数", "number"); stop();
      casewhen(4); start(); entity("脚本", "string"); stop();
      casewhen(3); start();
         selectcase("物品数量", "武器数量", "防具数量", "角色", "敌人", "地图人物", "队伍", end_item());
           casewhen(0); start(); entity("物品", "item"); stop();
           casewhen(1); start(); entity("武器", "weapon"); stop();
           casewhen(2); start(); entity("防具", "armor"); stop();
           casewhen(3); 
           start();
               entity("角色", "actor_index"); enumcase("参数", "等级", "Exp", "HP", "MP", 
              "MHP", "MMP", "ATK", "DEF", "MAT", "MDF", "AGI", "LUK"); 
            stop();
           casewhen(4); start(); entity("敌人", "enemy_index"); enumcase("参数", "HP", "MP", 
              "MHP", "MMP", "ATK", "DEF", "MAT", "MDF", "AGI", "LUK"); stop();
           casewhen(5); 
           start(); 
              entity("事件", "map_event");
              enumcase("参数", "X坐标", "Y坐标", "方向", "屏幕X坐标", "屏幕Y坐标", end_item());
           stop();  
           casewhen(6); start(); entity("队伍序号", "party_index"); stop();
           casewhen(7);
           start();
             enumcase("其他数据", "地图ID", "队伍人数", "金钱", "步数", "游戏时间", "计时器", "存档回数", "战斗回数", end_item());
           stop();
          
      stop();    
    stop();
    cmd("脚本", 355);
    start();
      entity("脚本", "string");
    stop();
    
    cmd("脚本内容", 655);
    start();
      data();
    stop();
    
   
    cmd("文章内容", 401);
    start();
      data();
    stop();
   
    cmd("字幕内容", 405);
    start();
      data();
    stop();
    
    cmd("注释内容", 408);
    start();
      data();
    stop();
   
