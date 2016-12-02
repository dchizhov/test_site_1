<div class="panel-display panel-1row2cols clearfix" <?php if (!empty($css_id)) {
    print "id=\"$css_id\"";
} ?>>
    <div class="panel-3row2cols-row clearfix"><?php print $content['top1']; ?></div>
    <div class="panel-3row2cols-row clearfix"><?php print $content['top2']; ?></div>
    <div class="panel-3row2cols-row clearfix"><?php print $content['top3']; ?></div>
    <div style="float: left;"><?php print $content['left']; ?></div>
    <div style="float: left;"><?php print $content['center']; ?></div>
    <div style="float: left;"><?php print $content['right']; ?></div>
</div>
        