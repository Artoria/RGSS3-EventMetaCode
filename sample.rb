module EventEditorMeta
  def thing
   #place meta.c here
  end
end


class EventDisplay
  include EventEditorMeta
  def parse(eventlist)
    @str = ""
    eventlist.each{|x|
      @enable =  {}
      @event = x
      @pos = -1
      @kstr = ""
      thing
    }
    @str
  end
  
  def cmd(name, id)
    if @pos == -1 && @event.code == id
      @kstr = name + ":\n"
      @enable[@pos] = true
    else
      @enable[@pos] = false
    end
  end
  
  def start(); return unless @enable[@pos]; @enable[@pos + 1] = true; @pos += 1 end
  
  def stop
    return unless @enable[@pos]
    if @pos == @event.parameters.size
      @str << @kstr << "\n"
      @enable[@pos] = false  
      @pos -= 1
    end
    
    @enable[@pos] = false
    @pos -= 1
    
  end
  
  def entity(a, b)
    return unless @enable[@pos]
    @kstr << "#{a} #{b}(#{@event.parameters[@pos]})\n"
    @enable[@pos+1] = true
    @pos += 1
  end
  
  def end_item 
    nil
  end
  
  def selectcase(*names, enditem)
    return unless @enable[@pos]
    @kstr << names[@event.parameters[@pos]] << "\n"
  end
  
  def enumcase(caption, *names, enditem)
    return unless @enable[@pos]
    case @event.parameters[@pos] 
      when false then r = 0
      when true  then r = 1
      else r = @event.parameters[@pos]
    end
    @kstr << "#{caption} #{names[r]}\n"
    @enable[@pos+1] = true
    @pos += 1
  end
  
  def casewhen(id)
    return unless @enable[@pos]
    @enable[@pos+1] = id == @event.parameters[@pos]
  end
    
  def data
    @kstr << @event.parameters.join("\n")
    @enable[@pos+1] = true
    @pos += 1
  end
end

