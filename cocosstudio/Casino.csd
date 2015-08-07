<GameProjectFile>
  <PropertyGroup Type="Node" Name="Casino" ID="06ec084f-0997-429b-8bc4-cbd542298571" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="5" Speed="0.1667">
        <Timeline ActionTag="-191687175" Property="Alpha">
          <IntFrame FrameIndex="1" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="2" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="517021773" Property="Alpha">
          <IntFrame FrameIndex="1" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="2" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="3" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="89617638" Property="Alpha">
          <IntFrame FrameIndex="2" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="3" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="4" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="1599008800" Property="Alpha">
          <IntFrame FrameIndex="3" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="4" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="5" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="create" StartIndex="1" EndIndex="5">
          <RenderColor A="150" R="255" G="228" B="196" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Casino" Tag="276" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="bomb" ActionTag="-191687175" Tag="277" Alpha="0" IconVisible="False" LeftMargin="-63.0000" RightMargin="-63.0000" TopMargin="-81.0000" BottomMargin="-81.0000" ctype="SpriteObjectData">
            <Size X="126.0000" Y="162.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="asset/casinoBomb.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="coin" ActionTag="517021773" Tag="278" Alpha="0" IconVisible="False" LeftMargin="-67.5000" RightMargin="-67.5000" TopMargin="-67.5000" BottomMargin="-67.5000" ctype="SpriteObjectData">
            <Size X="135.0000" Y="135.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="asset/casinoCoin.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="thunder" ActionTag="89617638" Tag="279" Alpha="0" IconVisible="False" LeftMargin="-67.5000" RightMargin="-67.5000" TopMargin="-81.0000" BottomMargin="-81.0000" ctype="SpriteObjectData">
            <Size X="135.0000" Y="162.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="asset/casinoThunder.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="transport" ActionTag="1599008800" Tag="280" IconVisible="False" LeftMargin="-75.0000" RightMargin="-75.0000" TopMargin="-75.0000" BottomMargin="-75.0000" ctype="SpriteObjectData">
            <Size X="150.0000" Y="150.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="asset/casinoTransport.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>